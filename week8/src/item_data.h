#ifndef ITEM_DATA_H
#define ITEM_DATA_H

#include <wx/wx.h>
#include <wx/treebase.h>
#include "node.h"

class ItemData : public wxTreeItemData
{
public:
    ItemData(Node * data) : wxTreeItemData()
    {
        _data = data;
    }

    virtual ~ItemData(){}

    Node * getData() const
    {
        return _data;
    }

private:
    Node * _data; 
};

#endif
