#include <string>
#include <vector>
#include "frame.h"

#include <iostream>
using namespace std;

Frame::Frame(const wxChar *title, Node * root):wxFrame((wxFrame *) nullptr, -1, title, wxDefaultPosition, wxSize(900, 800))
{
    // tree
    _tree = new wxTreeCtrl(this, TREE_ID, wxPoint(0,0), wxSize(300,800), 
    wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );

    std::string rootName = string(root->name());
    rootName += ", ";
    rootName += std::to_string(root->size());

    wxTreeItemId rootId = _tree->AddRoot(rootName);
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
    EVT_BUTTON(SAVE_ID, Frame::OnSave)
    EVT_TREE_SEL_CHANGED(TREE_ID, Frame::OnClick)
    EVT_TREE_END_LABEL_EDIT(TREE_ID, Frame::OnEdit)
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
            wxTreeItemId newItem = _tree->AppendItem(parent, nodeName);
            TreeBuilder((*it), newItem);
        }
    }
    catch (std::string e) {}
}

void Frame::OnSave(wxCommandEvent & WXUNUSED(event))
{
    wxFileDialog * SaveDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
    if ( SaveDialog->ShowModal() == wxID_OK )
    {
        _mainEditBox->SaveFile(SaveDialog->GetPath());
    }
    SaveDialog->Close();
}

void Frame::OnClick(wxTreeEvent& event)
{
    _itemText = _tree->GetItemText(event.GetItem());
}

void Frame::OnEdit(wxTreeEvent& event)
{
    
}
