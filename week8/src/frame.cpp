#include <string>
#include <vector>
#include <sys/stat.h>
#include "frame.h"
#include "item_data.h"

#include <fstream>
#include <cctype>

#include <iostream>
using namespace std;

Frame::Frame(const wxChar *title, Node * root):wxFrame((wxFrame *) nullptr, -1, title, wxDefaultPosition, wxSize(900, 800))
{
    // tree
    _tree = new wxTreeCtrl(this, TREE_ID, wxPoint(0,0), wxSize(300,800), 
    wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );

    std::string rootName = root->name();
    rootName += ", ";
    rootName += std::to_string(root->size());

    wxString path = root->getPath(); 
    wxTreeItemId rootId = _tree->AddRoot(rootName, -1, -1, new ItemData(path));
    TreeBuilder(root ,rootId);

    _tree->ExpandAllChildren(rootId);

    // text
    _mainEditBox = new wxTextCtrl(this, -1, _T("Type some text..."),
    wxPoint(310, 0), wxSize(600, 650), wxTE_MULTILINE);

    // button
    _saveButton = new wxButton(this, SAVE_ID, wxT("Save"), 
    wxPoint(310, 650), wxSize(590, 100));

    Connect(SAVE_ID, wxEVT_COMMAND_BUTTON_CLICKED, 
    wxCommandEventHandler(Frame::OnSave));
}

BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_BUTTON(SAVE_ID, Frame::OnSave)              // save button
    EVT_TREE_SEL_CHANGED(TREE_ID, Frame::OnClick)   // click item
    EVT_TREE_END_LABEL_EDIT(TREE_ID, Frame::OnEdit) // edit item
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

            wxString path = (*it)->getPath(); 
            wxTreeItemId newItem = _tree->AppendItem(parent, nodeName, -1, -1, new ItemData(path));
            TreeBuilder((*it), newItem);
        }
    }
    catch (std::string e) {}
}

void Frame::OnSave(wxCommandEvent & WXUNUSED(event))
{
    if (_mainEditBox->IsModified())
    {

    }
    // _mainEditBox->SaveFile(SaveDialog->GetPath());
}

void Frame::OnClick(wxTreeEvent& event)
{
    // _itemText = _tree->GetItemText(event.GetItem());
    // cout<<_itemText<<endl;

    ItemData * nodePath = (ItemData *)_tree->GetItemData(event.GetItem());
    TextLoad(nodePath->getData());
}

void Frame::OnEdit(wxTreeEvent& event)
{
    
}

bool isBinary(const char * path)
{
    ifstream inFile;
    inFile.open(path); 

    inFile.seekg(0,ios::end);
    long length = inFile.tellg();
    inFile.seekg(0,ios::beg);

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

    if (type == 1)
    {
        return false;
    }
    else
    {
        return true;
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
            noDisplay = true;
        }
        else if (S_ISDIR(st.st_mode)) // folder
        {
            _mainEditBox->Clear();
        }

        if (noDisplay)
        {
            _mainEditBox = new wxTextCtrl(this, -1, _T("The file is not displayed in the editor because it uses an unsupported text encoding."),
            wxPoint(310, 0), wxSize(600, 650), wxTE_MULTILINE);
            noDisplay = false;
        }
    }
}
