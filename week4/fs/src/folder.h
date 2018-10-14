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
            //totalFind = "";
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

        string classType() const
        {
            return "Folder";
        }

    private:
        vector<Node *> _children;
        string totalFind;

        string findName(string nodeName, string temp)
        {
            totalFind.clear();
            recursion(nodeName, temp);
            return totalFind;
        }

        string recursion(string nodeName, string temp)
        {
            if (Node::_nodeName==nodeName)
            {
                temp += "/"; temp += nodeName; temp += '\n';
                totalFind += temp;  
            }
            
            for (int i = 0; i < _children.size(); i++)
            {
                temp += "/"; temp += _children[i]->name();


            /*
                temp += "/"; temp += _children[i]->name();
                if (_children[i]->classType()=="Folder")
                {
                    cout<<temp<<endl;

                    recursion(nodeName, temp);
                    // backtracking 
                    temp.pop_back(); //temp -= "/"; 
                    temp.substr(0, (temp.size())-(_children[i]->name().size()));//temp -= _children[i]->name();
                    cout<<temp<<endl;
                }
                else if (_children[i]->classType()=="File")
                {
                    if (nodeName==_children[i]->name())
                    {
                        temp += "/"; temp += nodeName; temp += '\n';
                        totalFind += temp;  
                    }
                }
                else
                {
                    throw string("Error.");
                }*/
            }
        return temp;
        }
};
#endif
