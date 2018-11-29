#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H

#include <string>
#include <vector>
#include "node_visitor.h"

using namespace std;

class FindNodeByPathnameVisitor: public NodeVisitor
{
    public:
    FindNodeByPathnameVisitor(vector<string>* pathnames){}
    virtual ~FindNodeByPathnameVisitor(){}
    void visitFolder(Folder * folder);
    void visitFile(File * file);
    void visitLink(Link * link);
    Node * getNode() const;
    // return the Node object if the path indicate the node in the file system, 
    // and if not, return nullptr.

    private:
    _pathnames
};

#endif
