#include "find_visitor.h"
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"

FindVisitor::FindVisitor(std::string name) : _name(name)
{
}

void FindVisitor::visitFile(File *file)
{
    if (_name == file->name())
    {
        _nodeNamePath = file->name();
    }
    else
    {
        _nodeNamePath = "";
    }
}

void FindVisitor::visitFolder(Folder *folder)
{
    std::vector<Node *> samePath;
    FindSameNodeName(folder, samePath);

    _nodeNamePath = "";
    for (int i = 0; i < samePath.size(); i++)
    {
        _nodeNamePath += "./";
        _nodeNamePath += samePath[i]->getPath().substr(folder->getPath().length() + 1, samePath[i]->getPath().length() - folder->getPath().length());
        if ((i + 1) != samePath.size())
            _nodeNamePath += "\n";
    }
}

void FindVisitor::visitLink(Link *link)
{
    if (_name == link->name())
    {
        _nodeNamePath = link->name();
    }
    else
    {
        _nodeNamePath = "";
    }
}

void FindVisitor::FindSameNodeName(Node *n, std::vector<Node *> &answer)
{
    try
    {
        NodeIterator *it = n->createIterator();
        for (it->first(); !it->isDone(); it->next())
        {
            Node *node = it->currentItem();
            if (_name == node->name())
            {
                answer.push_back(node);
            }
            FindSameNodeName(node, answer);
        }
    }
    catch (std::string line)
    {
        line = "number of children: not applicable\n";
    }
}
