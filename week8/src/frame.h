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
    void OnClick(wxTreeEvent& event);
    void OnEdit(wxTreeEvent& event);

    wxTreeCtrl * _tree;
    wxButton * _saveButton;

private:
    wxTextCtrl * _mainEditBox;
    Node * _root;
    wxString _itemText;

    DECLARE_EVENT_TABLE()
};

const int TREE_ID = 101;
const int SAVE_ID = 102;

#endif
