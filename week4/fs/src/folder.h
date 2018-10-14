#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "node.h"

using namespace::std;

class Folder: public Node
{
    public:

        Folder(const char *path): Node(path)
        {
            
        }

        string find(string nodeName)
        {
            string temp = "";
            return findName(nodeName, temp);
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

    private:
        vector<Node *> _children;
        string totalFind;

        string findName(string nodeName, string temp)
        {
            totalFind = "";
            findRecursion(nodeName, temp);
            return totalFind;
        }

        string findRecursion(string nodeName, string temp)
        {
            if (Node::_nodeName==nodeName)
            {
                temp += "/"; temp += nodeName; temp += '\n';
                totalFind += temp;
            }

            for (int i = 0; i < _children.size(); i++)
            {
                temp += "/"; temp += _children[i]->name();
                cout<<"type: "<<typeid(_children[i]).name()<<endl;
                //findRecursion(nodeName, temp);
                /*
                if (_children[i])
                {
                    findRecursion(nodeName, temp);
                }
                else
                {

                }*/
                
                // backtracking 
                //temp.pop_back(); //temp -= "/"; 
                //temp.substr(0, (temp.size())-(_children[i]->name().size()));//temp -= _children[i]->name();
            } 
        }
};
#endif
