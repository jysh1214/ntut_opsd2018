#ifndef FRAME_H
#define FRAME_H

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/textctrl.h>

#include "node.h"

class Frame : public wxFrame
{
public:
    Frame(const wxChar *title, Node * root);
    virtual ~Frame(){}

    void TreeBuilder(Node * node, wxTreeItemId parent);
    void OnSave(wxCommandEvent & WXUNUSED(event));
    void OnKeyDown(wxKeyEvent& event);
    void OnClick(wxTreeEvent& event);
    void OnEdit(wxTreeEvent& event);
    void TextLoad(wxString wxs_path);
    void SaveModule();

    wxTreeCtrl * _tree;
    wxButton * _saveButton;

private:
    wxTextCtrl * _mainEditBox;
    Node * _root;
    Node * _itemNode;

    DECLARE_EVENT_TABLE()
};

const int TREE_ID = 101;
const int TEXT_ID = 102;
const int SAVE_ID = 103;

#endif
