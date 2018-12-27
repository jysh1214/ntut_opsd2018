#include <string>
#include <vector>
#include <sys/stat.h>
#include <wx/string.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include <wx/kbdstate.h>
#include "frame.h"
#include "item_data.h"

#include <fstream>
#include <cctype>

wxString removeComma(wxString wxs_text)
{
    wxString answer;
    int p = 0;
    bool done = false;
    for (wxString::size_type i = 0; i < wxs_text.size(); i++)
    {
        if (wxs_text[i] == ',')
        {
            answer = wxs_text.SubString(0, p-1);
            done = true;
            break;
        }
        else { p++; }
    }
    if (!done)
    {
        answer = wxs_text;
    }
    return answer;
}

wxString replace(wxString path, wxString name)
{
    wxString newPath;
    for (wxString::size_type i = path.size(); i > 0; i--)
    {
        if (path[i] == '/')
        {
            newPath = path.SubString(0, path.size()-i+2);
            newPath += removeComma(name);
            break;
        }
    }
    return newPath;
}

void renameFile(wxString oldPath, wxString newPath)
{
    std::rename(oldPath.mb_str(), newPath.mb_str());
}

bool isBinary(const char * path)
{
    std::ifstream inFile;
    inFile.open(path); 

    inFile.seekg(0,std::ios::end);
    long length = inFile.tellg();
    inFile.seekg(0,std::ios::beg);

    char* buffer = 0;
    buffer = new char[length];
    inFile.get(buffer,length);
    bool type = 1;
    int i = 0;

    do
    {
        type = isascii(buffer[i]);
        i++;
    }
    while ((i < length) && (type == 1));

    inFile.close();
    delete buffer;

    if (type == 1) return false;
    else return true;
}

Frame::Frame(const wxChar *title, Node * root):wxFrame((wxFrame *) nullptr, -1, title, wxDefaultPosition, wxSize(900, 800))
{ 
    CreateStatusBar(1);

    /*** hot key panel ***/
    wxPanel * HotKeyPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);

    /*** tree ***/
    _tree = new wxTreeCtrl(this, TREE_ID, wxPoint(0,0), wxSize(300,800), 
    wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );

    _root = root;

    std::string rootName = _root->name();
    rootName += ", ";
    rootName += std::to_string(_root->size());
 
    wxTreeItemId rootId = _tree->AddRoot(rootName, -1, -1, new ItemData(_root));
    TreeBuilder(_root ,rootId);

    _tree->ExpandAllChildren(rootId);

    /*** text ***/
    _mainEditBox = new wxTextCtrl(this, TEXT_ID, _T("Type some text..."),
    wxPoint(310, 0), wxSize(600, 650), wxTE_MULTILINE);

    /*** button ***/
    _saveButton = new wxButton(this, SAVE_ID, wxT("Save"), 
    wxPoint(310, 650), wxSize(590, 100));

    Connect(SAVE_ID, wxEVT_COMMAND_BUTTON_CLICKED, 
    wxCommandEventHandler(Frame::OnSave));
}

BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_BUTTON(SAVE_ID, Frame::OnSave)                // save button
    EVT_CHAR_HOOK(Frame::OnKeyDown)                   // hot key
    EVT_TREE_SEL_CHANGED(TREE_ID, Frame::OnClick)     // click item
    EVT_TREE_END_LABEL_EDIT(TREE_ID, Frame::OnEdit)   // edit item
END_EVENT_TABLE()

void Frame::TreeBuilder(Node * node, wxTreeItemId parent)
{
    try
    {
        std::vector<Node *> children = node->getChildren();
        for (std::vector<Node *>::iterator it = children.begin(); it != children.end(); it ++)
        {
            std::string nodeName = (*it)->name();
            nodeName += ", ";
            nodeName += std::to_string((*it)->size());

            wxTreeItemId newItem = _tree->AppendItem(parent, nodeName, -1, -1, new ItemData((*it)));
            TreeBuilder((*it), newItem);
        }
    }
    catch (std::string e) {}
}

void Frame::OnSave(wxCommandEvent& WXUNUSED(event))
{
    SaveModule();
}

void Frame::OnKeyDown(wxKeyEvent& event)
{  
    if (event.ControlDown() && (int)event.GetKeyCode() == 83)
    {
        SaveModule();
    }
    event.Skip();
}

void Frame::OnClick(wxTreeEvent& event)
{ 
    ItemData * itemNode = (ItemData *)_tree->GetItemData(event.GetItem());
    Node * node = itemNode->getData();
    _itemNode = node;
    TextLoad(node->getPath());
}

void Frame::OnEdit(wxTreeEvent& event)
{
    wxString oldLabel = _tree->GetItemText(event.GetItem());
    wxString newLabel = event.GetLabel();
    
    if (newLabel == "" || newLabel == oldLabel)
    {
        event.Veto();
    }
    else
    {
        wxString editMessage = "label edit: ";
        editMessage += newLabel;
        editMessage += "-- old name was ";
        editMessage += removeComma(oldLabel);

        /*** message box ***/
        int answer = wxMessageBox(editMessage, "Confirm", 
        wxCANCEL | wxYES_NO | wxYES_DEFAULT | wxICON_QUESTION);

        if (answer == wxYES)
        {
            ItemData * itemNode = (ItemData *)_tree->GetItemData(event.GetItem());
            Node * node = itemNode->getData();
            wxString oldPath = node->getPath();
            wxString newPath = replace(oldPath, newLabel);
            renameFile(oldPath, newPath);
        }
        else { event.Veto(); }
    }
}

void Frame::TextLoad(wxString wxs_path)
    {
    const char * path = wxs_path.mb_str();
    struct stat st;
    bool noDisplay = false;
    if (lstat(path, &st) == 0)
    {
        if (S_ISREG(st.st_mode)) // file
        {
            // check is text file or binary file
            isBinary(path) ?
            noDisplay = true :
            _mainEditBox->LoadFile(wxs_path);
        }
        else if (S_ISLNK(st.st_mode)) // link
        {
            _mainEditBox = new wxTextCtrl(this, -1, 
            _T("This is the link."),
            wxPoint(310, 0), wxSize(600, 650), wxTE_MULTILINE);
        }
        else if (S_ISDIR(st.st_mode)) // folder
        {
            _mainEditBox->Clear();
        }

        if (noDisplay)
        {
            _mainEditBox = new wxTextCtrl(this, -1, 
            _T("The file is not displayed in the editor because it uses an unsupported text encoding."),
            wxPoint(310, 0), wxSize(600, 650), wxTE_MULTILINE);
            noDisplay = false;
        }
    }
}

void Frame::SaveModule()
{
    if (_mainEditBox->IsModified())
    {
        /*** message box ***/
        int answer = wxMessageBox("You want to save?", "Confirm", 
        wxCANCEL | wxYES_NO | wxYES_DEFAULT | wxICON_QUESTION);

        if (answer == wxYES)
        {
            wxString itemPath = _itemNode->getPath();
            _mainEditBox->SaveFile(itemPath, wxTEXT_TYPE_ANY)?
            SetStatusText(_T("Saved"), 0) :
            SetStatusText(_T("Saved Failed"), 0);
        }
        else { SetStatusText(_T("Cancel Save"), 0); }
    }
    else 
    { 
        // user do nothing 
    }
}
