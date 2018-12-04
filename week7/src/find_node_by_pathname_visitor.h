#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H

#include <string>
#include <vector>
#include "node_visitor.h"
#include <iostream>
using namespace std;

class FindNodeByPathnameVisitor: public NodeVisitor
{
    public:
    FindNodeByPathnameVisitor(vector<string>* pathnames): _myvector(pathnames)
    {
    	string temp = "./";
        for (vector<string>::iterator it = pathnames->begin() ; it != pathnames->end(); ++it)
        {
        	if (it != pathnames->begin()) temp += "/";
            temp += (*it);
        }
        _pathnames = temp;

    }
    virtual ~FindNodeByPathnameVisitor(){}
    void visitFolder(Folder * folder);
    void visitFile(File * file);
    void visitLink(Link * link);
    Node * getNode();
    // return the Node object if the path indicate the node in the file system, 
    // and if not, return nullptr.

    void findNode(Node * node);

    private:
    vector<string> * _myvector;
    string _pathnames;
    Node * _node;
};

#endif
