from flask import Flask, request, abort
# line bot api
from linebot import (
    LineBotApi, WebhookHandler
)
from linebot.exceptions import (
    InvalidSignatureError
)
from linebot.models import *

# from imgurpython import ImgurClient
# from imgurpython.helpers.error import ImgurClientError

# import subprocess
import tempfile, shutil, os
from PIL import Image
from io import BytesIO

import json
import sys
import urllib.request
import urllib.error
import time
import datetime
import gspread
# google api
from oauth2client.service_account import ServiceAccountCredentials as SAC
# django
from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt

from config import channel_access_token, channel_secret
# from config import client_id, client_secret, album_id, access_token, refresh_token

#from pydarknet import Detector, Image

import LineWebhook

app = Flask(__name__)

# Channel Access Token
line_bot_api = LineBotApi(channel_access_token)
# Channel Secret
handler = WebhookHandler(channel_secret)

# Google Sheet Config
GDriveJSON = 'LineBotSheet.json'
GSpreadSheet = 'LineBotSheet'

static_tmp_path = os.path.join(os.path.dirname(__file__), 'static', 'tmp')

# 監聽所有來自 /callback 的 Post Request
@app.route("/callback", methods=['POST'])
def callback():
    # get X-Line-Signature header value
    signature = request.headers['X-Line-Signature']
    # get request body as text
    body = request.get_data(as_text=True)
    app.logger.info("Request body: " + body)
    # handle webhook body
    try:
        handler.handle(body, signature)
    except InvalidSignatureError:
        abort(400)
    return 'OK'

# 處理 event
@handler.add(FollowEvent)
def handle_follow(event):
    pass

@handler.add(UnfollowEvent)
def handle_unfollow(event):
    pass

@handler.add(JoinEvent)
def handle_join(event):
    pass

@handler.add(LeaveEvent)
def handle_leave(event):
    pass


# 處理文字訊息
@handler.add(MessageEvent, message=TextMessage)
def handle_text_message(event):

    # 檢查有無權限 查看有無會員資格
    profile = line_bot_api.get_profile(event.source.user_id)
    # print(profile.display_name)
    # print(profile.user_id)
    # print(profile.picture_url)
    # print(profile.status_message)
    permision = False
    # 查看Google Sheet看有無在名單上

    # 連線至Google Sheet
    try:
        scope = ['https://spreadsheets.google.com/feeds',
                 'https://www.googleapis.com/auth/drive',
                 'https://www.googleapis.com/auth/drive.readonly',
                 'https://www.googleapis.com/auth/drive.file',
                 'https://www.googleapis.com/auth/spreadsheets',
                 'https://www.googleapis.com/auth/spreadsheets.readonly']
        key = SAC.from_json_keyfile_name(GDriveJSON, scope)
        gc = gspread.authorize(key)
        worksheet = gc.open(GSpreadSheet).sheet1 # sheet1: member

    except Exception as ex:
        print('無法連線Google Sheet', ex)
        message = TextSendMessage(text="無法連線到Google Sheet")
        line_bot_api.reply_message(event.reply_token, message)
        sys.exit(1)
        return 0

    # 使用Google Sheet
    try:
        text = "RS"
        date = json.dumps(datetime.datetime.now(), cls=Encoder, indent=4)
        worksheet.append_row((date, text))
        spreadsheet_id = '1csBFk9tCGJ0G2syaLUWoHp_OH9depz919rO5RQ2hSk0'

        name_list = worksheet.col_values(3) # column: c name
        for name in name_list:
            if (profile.display_name == name):
                permision = True
                # message = TextSendMessage(text="歡迎")
                # line_bot_api.reply_message(event.reply_token, message)

        if (not permision):
            message = TextSendMessage(text="權限錯誤 您不是會員")
            line_bot_api.reply_message(event.reply_token, message)
        # gsheet = worksheet().values().get(spreadsheetId=spreadsheet_id, range=GSpreadSheet).execute()
        return 0

    except Exception as ex:    
        print('無法使用Google Sheet', ex)
        message = TextSendMessage(text="無法使用Google Sheet")
        line_bot_api.reply_message(event.reply_token, message)
        sys.exit(1)
        return 0
    
    # return 0

    # # 使用Line ID確認
    # permision = False
    # for i in range(1, sheet.row_count):
    #     val = sheet.cell(i, 'H').value
    #     if (profile.user_id == val):
    #         permision = True
    #         action = event.message.text
    #         message = LineWebhook.actionDispatcher(action)

    # if (not permision):
    #     message = TextSendMessage(text="權限錯誤：您沒有執行此指令之權限")
    #     line_bot_api.reply_message(event.reply_token, message)
    #     return 0
        


    
    


    # message = TextSendMessage(text="請輸入圖片")
    # line_bot_api.reply_message(event.reply_token, message)
    # return 0

# 處理圖片訊息
@handler.add(MessageEvent, message=ImageMessage)
def handle_image_message(event):
    # save image
    try:
        message_content = line_bot_api.get_message_content(event.message.id)
        i = Image.open(BytesIO(message_content.content))
        filename = './images/' + event.message.id + '.jpg'
        i.save(filename)

        message = TextSendMessage(text="上傳成功，開始辨識")
        line_bot_api.reply_message(event.reply_token, message)
    
    except:
        message = TextSendMessage(text="系統錯誤，請重新上傳一次")
        line_bot_api.reply_message(event.reply_token, message)

        return 0     

'''Create an encoder subclassing JSON.encoder. 
Make this encoder aware of our classes (e.g. datetime.datetime objects) 
'''
class Encoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, datetime.datetime):
            return obj.isoformat()
        else:
            return json.JSONEncoder.default(self, obj)

def get_google_sheet(spreadsheet_id, range_name):
    """ Retrieve sheet data using OAuth credentials and Google Python API. """
    # scopes = 'https://www.googleapis.com/auth/spreadsheets.readonly'
    # Setup the Sheets API
    # store = file.Storage('credentials.json')
    # creds = store.get()
    # if not creds or creds.invalid:
    #     flow = client.flow_from_clientsecrets('client_secret.json', scopes)
    #     creds = tools.run_flow(flow, store)
    # service = build('sheets', 'v4', http=creds.authorize(Http()))

    # Call the Sheets API
    gsheet = service.spreadsheets().values().get(spreadsheetId=spreadsheet_id, range=range_name).execute()
    return gsheet

import os
if __name__ == "__main__":
    port = int(os.environ.get('PORT', 5000))
    app.run(host='0.0.0.0', port=port)
