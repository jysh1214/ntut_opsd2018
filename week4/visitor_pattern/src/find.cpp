#include "find.h"
#include "node.h"
#include "file.h"
#include "folder.h"

Find::Find(string nodeName): _nodeName(nodeName)
{
    _answer;
}

void Find::visitFile(File *file)
{
    Action *n = new Name();
    file->accept(n);
    if (n->getName()==_nodeName) _answer = _nodeName;
    else _answer = "";
}

void Find::visitFolder(Folder *folder)
{
    vector<Node *> totalFind;
    string findList = "";
    string temp = "";

    this->findName(totalFind, folder); //recursion

    if (totalFind.size()==0) _answer = "";
    
    for (int i = 0; i < totalFind.size(); i++)
    { 
        int x = (folder->getPath()).size();
        temp += ".";
        temp += (totalFind[i]->getPath()).substr(x, (totalFind[i]->getPath()).size());
        findList += temp; 
        temp.clear();
        if (i!=totalFind.size()-1) findList+= '\n';
    }
    _answer = findList;
}

void Find::findName(vector<Node *>& answer, Node *node)
{
    try
    {
        vector<Node *> children = node->getChildren();
        for (int i = 0; i < children.size(); i++)
        {
            Node *node = children[i];
            Action *n = new Name();
            node->accept(n);
            if (n->getName() == _nodeName) answer.push_back(node);
            this->findName(answer, node);
        }        
    }
    catch (string e)
    {

    }
}
