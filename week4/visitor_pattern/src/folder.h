#ifndef FOLDER_H
#define FOLDER_H

#include <memory>
#include <vector>
#include <string>
#include "node.h"
#include "action.h"
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
                    if (isDone()) throw string("no current item.");
                    return *_it;
                }

                void next()
                {
                    if (isDone()) throw string("moving past the end");
                    _it++;
                }

                bool isDone()
                {
                    return (_it == _folder->_children.end());
                }

            private:
                Folder *_folder;
                vector<Node*>::iterator _it;
        };


        Folder(const char *path): Node(path)
        {
            
        }

        void add(Node *node)
        {
            _children.push_back(node);
        }

        int numberOfChildren() const
        {
            return _children.size();
        }

        void accept(Action *visitor)
        {
            visitor->visitFolder(this);
        }

        NodeIterator * createIterator()
        {
            return new FolderIterator(this);
        }

        vector<Node *> getChildren() const
        {
            return _children;
        }
        
    private:
        vector<Node *> _children;
};
#endif
