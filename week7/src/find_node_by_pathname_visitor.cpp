#include "find_node_by_pathname_visitor.h"
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <iostream>

using namespace std;

void FindNodeByPathnameVisitor::visitFolder(Folder * folder)
{
    _node = nullptr;
    this->findNode(folder); //recursion
}

void FindNodeByPathnameVisitor::visitFile(File * file)
{
    _node = nullptr;

    if (file->getPath() == _pathnames) _node = file;

    for (vector<string>::iterator it = _myvector->begin() ; it != _myvector->end(); ++it)
    {
        if (file->name() == (*it)) _node = file;
    }
}

void FindNodeByPathnameVisitor::visitLink(Link * link)
{
    _node = nullptr;
    if (link->getPath() == _pathnames) _node = link;

    for (vector<string>::iterator it = _myvector->begin() ; it != _myvector->end(); ++it)
    {
        if (link->name() == (*it)) _node = link;
    }
}

Node * FindNodeByPathnameVisitor::getNode()
{
    return _node;
}

void FindNodeByPathnameVisitor::findNode(Node * node)
{   
    try
    {
        NodeIterator *it = node->createIterator();

        if (node->getPath() == _pathnames) _node = node;

        for (it->first(); !it->isDone(); it->next())
        {
            Node *newNode = it->currentItem();

            
            if (newNode->getPath() == _pathnames)
            {
                _node = newNode;
            }

            // convert '.' to '_'
            string temp = newNode->name();
            for(string::size_type i = 0; i < temp.size(); ++i)
            {
                if (temp[i] == '.') 
                {
                    temp.replace(i, 1, "_");
                }                
            }
            // check twice
            for (vector<string>::iterator it = _myvector->begin() ; it != _myvector->end(); ++it)
            {
                if (temp == (*it)) _node = newNode;
            }

            findNode(newNode);
        }
    }
    catch (string e)
    {

    }
}
