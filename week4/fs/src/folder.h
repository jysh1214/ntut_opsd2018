#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "node.h"

using namespace::std;
template<class T> void findName (T, string);

class Folder: public Node
{
    public:

        Folder(const char *path): Node(path)
        {
            
        }

        string find(string nodeName)
        {
            string findList = "";
            string temp = "";

            findName(this, nodeName);
            
            for (int i = 0; i < this->totalFind.size(); i++)
            {
                int x = (this->getPath()).size();
                int y = (this->name()).size();
                temp += (totalFind[i]->getPath()).substr(x-y, (totalFind[i]->getPath()).size());
                findList += temp; 
                temp.clear();
                if (i!=totalFind.size()-1) findList+= '\n';
            }
            return findList;
        }

        void add(Node *node)
        {
            _children.push_back(node);
        }

        int infoContent() const
        {
            int sum = 0;
            for (int i = 0; i < _children.size(); i++)
            {
                sum += _children[i]->infoContent();
            }
            return sum;
        }

        int numberOfChildren() const
        {
            return _children.size();
        }

        string classType() const
        {
            return "Folder";
        }
        
    private:
        vector<Node *> _children;
        vector<Node *> totalFind;

        void findName (Node *node, string nodeName)
        {
            if (node->name()==nodeName) totalFind.push_back(node);

            if (node->classType()=="Folder")
            {
                for (int i = 0; i < _children.size(); i++)
                {
                    findName(_children[i], nodeName);
                }
            }
        }
};
#endif
