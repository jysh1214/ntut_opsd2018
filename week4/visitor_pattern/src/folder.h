#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "node.h"
#include "action.h"
#include "name.h"

using namespace std;

class Folder: public Node
{
    public:
        friend class Action;
        friend class Name;
        friend class Find;

        Folder(const char *path): Node(path)
        {
            
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

        // string find(string nodeName) const
        // {
        //     vector<Node *> totalFind;
        //     string findList = "";
        //     string temp = "";

        //     this->findName(nodeName, totalFind);

        //     if (totalFind.size()==0) return "";
            
        //     for (int i = 0; i < totalFind.size(); i++)
        //     { 
        //         int x = (this->getPath()).size();
        //         temp += ".";
        //         temp += (totalFind[i]->getPath()).substr(x, (totalFind[i]->getPath()).size());
        //         findList += temp; 
        //         temp.clear();
        //         if (i!=totalFind.size()-1) findList+= '\n';
        //     }
        //     return findList;
        // }

        void findName (string nodeName, vector<Node *>& answer) //const
        {
            for (int i = 0; i < _children.size(); i++)
            { 
                Node *node = this->_children[i];
                if (node->name() == nodeName) 
                {
                    answer.push_back(node);
                }
                node->findName(nodeName, answer);
            }
        }

        string accept(Action *visitor)
        {
            return visitor->visitFolder(this);
        }

        vector<Node *> getChildren()
        {
            return _children;
        }

        string classType()
        {
            return "Folder";
        }
        
    private:
        vector<Node *> _children;
 
};
#endif
