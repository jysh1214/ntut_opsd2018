#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <string>

using namespace::std;

class Node
{
    public:
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

        std::string getPath() const
        {
            return _path;
        }

        std::string name() const
        {
            string nodeName;
            string tempStr = this->_path;
            nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));

            return nodeName;
        }

        virtual std::string find(std::string nodeName) const = 0;

        virtual void findName(std::string nodeName, std::vector<Node *>& answer) const{}

  private:
      const char * _path;
      struct stat _st;
};
#endif
