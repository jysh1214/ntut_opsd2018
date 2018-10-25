#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <vector>
#include <string>
#include "action.h"
#include "name.h"

class Action;

using namespace::std;

class Node
{
    public:
        friend class Action;
        friend class Name;

        Node(const char * path): _path(path)
        {
            lstat(_path, &_st);
            if (lstat(_path, &_st) == -1) throw std::string("No such file or directory.");
        }

        int size() const
        {
            return _st.st_size;
        }

        virtual int infoContent() const
        {
            return size();
        }

        virtual void add(Node *node)
        {
            throw string("unable to add\n");
        }

        virtual int numberOfChildren() const
        {
            throw string("number of children: not applicable\n");
        }

        string getPath() const
        {
            return _path;
        }

        string name() const
        {
            string nodeName;
            string tempStr = this->_path;
            nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));

            return nodeName;
        }

        // virtual string find(string nodeName) const = 0;

        virtual void findName(string nodeName, std::vector<Node *>& answer) //const
        {

        }

        virtual string accept(Action *visitor)
        {

        }

        virtual vector<Node *> getChildren()
        {

        }

        virtual string classType()
        {
            
        }

  private:
      const char * _path;
      struct stat _st;
};
#endif
