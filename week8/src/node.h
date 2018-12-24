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
    Node(const char * path)
    {
        lstat(path, &_st);
        if (lstat(path, &_st) == -1)
        {
            throw std::string("No such file or directory.");
        }
        wxs_path = wxString::FromUTF8(path);
        std::string tempStr = path;
        _name = tempStr.substr(tempStr.find_last_of("/") + 1, tempStr.length() - tempStr.find_last_of("/"));
    }

    virtual ~Node(){}

    wxString getPath() const
    {
        return wxs_path;
    }

    std::string name() const
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
    std::string _name;
    wxString wxs_path;
    struct stat _st;
};

#endif
