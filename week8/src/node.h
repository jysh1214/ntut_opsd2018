#ifndef NODE_H
#define NODE_H

#include <wx/wx.h>
#include <sys/stat.h>
#include <string>
#include <vector>

#include <iostream>
using namespace std;

class Node
{
public:
    Node(char *path) : _path(path)
    {
        lstat(_path, &_st);
        if (lstat(_path, &_st) == -1)
        {
            throw std::string("No such file or directory.");
        }

        std::string tempStr = _path;

        _name= tempStr.substr(tempStr.find_last_of("/") + 1, 
        tempStr.length() - tempStr.find_last_of("/"));
    }

    virtual ~Node(){}

    std::string getPath()
    {  
        return _path;
    }

    std::string name()
    {
        return _name;
    }

    int size() const
    {
        return _st.st_size;
    }

    virtual void add(Node *node)
    {
        throw std::string("unable to add\n");
    }

    virtual std::vector<Node *> getChildren()
    {
        throw std::string("unable to use\n");
    }

private:
    char *_path;
    std::string _name;
    struct stat _st;
};

#endif
