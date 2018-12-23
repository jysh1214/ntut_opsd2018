#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <string>
#include <vector>

class Node
{
public:
    Node(const char *path) : _path(path)
    {
        lstat(_path, &_st);
        if (lstat(_path, &_st) == -1)
        {
            throw std::string("No such file or directory.");
        }
    }
    virtual ~Node(){}

    std::string getPath() const
    {
        return _path;
    }

    std::string name() const
    {
        std::string nodeName;
        std::string tempStr = this->_path;
        nodeName = tempStr.substr(tempStr.find_last_of("/") + 1, tempStr.length() - tempStr.find_last_of("/"));
        return nodeName;
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
    const char *_path;
    struct stat _st;
};

#endif
