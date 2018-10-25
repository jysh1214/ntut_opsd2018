#include "find.h"
#include "node.h"
#include "file.h"
#include "folder.h"
#include <iostream>
Find::Find(string nodeName): _nodeName(nodeName)
{
    //_nodeName = nodeName;
}

string Find::visitFile(File *file)
{
    if (file->name()==_nodeName) return _nodeName;
    else return ("");
}

string Find::visitFolder(Folder *folder)
{
    vector<Node *> totalFind;
    string findList = "";
    string temp = "";

    // folder->findName(_nodeName, totalFind);
    this->findName(totalFind, folder);

    if (totalFind.size()==0) return "";
    
    for (int i = 0; i < totalFind.size(); i++)
    { 
        int x = (folder->getPath()).size();
        temp += ".";
        temp += (totalFind[i]->getPath()).substr(x, (totalFind[i]->getPath()).size());
        findList += temp; 
        temp.clear();
        if (i!=totalFind.size()-1) findList+= '\n';
    }
    return findList;
}

void Find::findName(vector<Node *>& answer, Node *node)
{
    if (node->classType()=="Folder")
    {
        vector<Node *> children = node->getChildren();
        for (int i = 0; i < children.size(); i++)
        {
            Node *node = children[i];
            if (node->name() == _nodeName) answer.push_back(node);
            this->findName(answer, node);
        }
    }
    else if (node->classType()=="File")
    {
        if (node->name() == _nodeName) answer.push_back(node);
    }
    else
    {
    	throw string ("Error.");
    }

}
