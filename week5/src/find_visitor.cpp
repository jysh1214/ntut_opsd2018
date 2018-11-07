#include <map>
#include "find_visitor.h"
#include "node.h"
#include "file.h"
#include "folder.h"

FindVisitor::FindVisitor(string name): _nodeName(name)
{
 
}

void FindVisitor::visitFile(File *file)
{
    if (file->name()==_nodeName) _answer = _nodeName;
    else _answer = "";
}

void FindVisitor::visitFolder(Folder *folder)
{
    map<string, Node *> totalFind;
    string findList = "";
    string temp = "";

    this->findName(totalFind, folder); //recursion

    if (totalFind.size()==0) _answer = "";

    for (map<string, Node *>::iterator it = totalFind.begin(); it!=totalFind.end(); it++)
    {  
        int x = (folder->getPath()).size();
        temp += ".";
        temp += (it->second)->getPath().substr(x, (it->second)->getPath().size());
        findList += temp;
        temp.clear();
        findList+= '\n';
    }

    _answer = findList.substr(0, findList.size()-1); //remove last '\n'
    
}

void FindVisitor::findName(map<string, Node *>& answer, Node *node)
{
    try
    {
        map<string, Node *> children = node->getChildren();
        for (map<string, Node *>::iterator it = children.begin(); it!=children.end(); it++)
        {
            Node *node = it->second;

            if (node->name() == _nodeName)
            {
                answer.insert(pair<string, Node *>(node->getPath(), node));
            }
            this->findName(answer, node);
        }
    }
    catch (string e)
    {

    }
}
