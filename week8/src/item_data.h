#ifndef ITEM_DATA_H
#define ITEM_DATA_H

#include <wx/wx.h>
#include <wx/treebase.h>

class ItemData : public wxTreeItemData
{
public:
    ItemData(wxString data) : wxTreeItemData()
    {
        _data = data;
    }

    virtual ~ItemData(){}

    wxString getData() const
    {
        return _data;
    }

private:
    wxString _data;
};

#endif
