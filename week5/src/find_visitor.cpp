#include <map>
#include "find_visitor.h"
#include "node.h"
#include "file.h"
#include "folder.h"

FindVisitor::FindVisitor(string name): _nodeName(name)
{
    _answer;
}

void FindVisitor::visitFile(File *file)
{
    NodeVisitor *n = new Name();
    file->accept(n);
    if (n->getName()==_nodeName) _answer = _nodeName;
    else _answer = "";
}

void FindVisitor::visitFolder(Folder *folder)
{
    map<string, Node *> totalFind;
    string findList = "";
    string temp = "";

    this->findName(totalFind, folder); //recursion

    if (totalFind.size()==0) _answer = "";
    
    for (int i = 0; i < totalFind.size(); i++)
    { 
        int x = (folder->getPath()).size();
        temp += ".";
        temp += (totalFind[to_string(i)]->getPath()).substr(x, (totalFind[to_string(i)]->getPath()).size());
        findList += temp;
        temp.clear();
        if (i!=totalFind.size()-1) findList+= '\n';
    }
    _answer = findList;
}

void FindVisitor::findName(map<string, Node *>& answer, Node *node)
{
    try
    {
        map<string, Node *> children = node->getChildren();
        for (int i = 0; i < children.size(); i++)
        {
            Node *node = children[to_string(i)];
            NodeVisitor *n = new Name();
            node->accept(n);
            if (n->getName() == _nodeName)
            {
                answer.insert(pair<string, Node *>(to_string(answer.size()), node));
            }
            this->findName(answer, node);
        }
    }
    catch (string e)
    {

    }
}
