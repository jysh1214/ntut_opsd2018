#ifndef FOLDER_H
#define FOLDER_H

#include <map>
#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"

using namespace std;

class Folder: public Node
{
    public:
        class FolderIterator: public NodeIterator
        {
            public:
                FolderIterator(Folder *f): _folder(f)
                {

                }

                void first()
                {
                    _it = _folder->_children.begin();
                }

                Node *currentItem()
                {
                    if (isDone()) throw string("no current item\n");
                    return _it->second;
                }

                void next()
                {
                    if (isDone()) throw string("moving past the end\n");
                    _it ++;
                }

                bool isDone()
                {
                    return (_it == _folder->_children.end());
                }

            private:
                Folder *_folder;
                map<string, Node *>::iterator _it;


        };

        Folder(const char *path): Node(path)
        {
            
        }

        void add(Node *node)
        {
            _children.insert(pair<string, Node *>(to_string(_children.size()), node));
        }

        int numberOfChildren() const
        {
            return _children.size();
        }

        void accept(NodeVisitor *visitor)
        {
            visitor->visitFolder(this);
        }

        map<string, Node *> getChildren() const
        {
            return _children;
        }

        NodeIterator * createIterator()
        {
            return new FolderIterator(this);
        }
        
    private:
        map<string, Node *> _children;
};
#endif
