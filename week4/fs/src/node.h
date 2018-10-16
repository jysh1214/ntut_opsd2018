#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <iostream>
#include <string>

using namespace::std;

class Node
{
    public:

        Node(const char *path): _path(path)
        {
            const char* _path = (const char*)malloc(sizeof(path));
            lstat(_path, &_st);
            stringPath = charPointerToString();
            _nodeName = getName();
        }
        
        string name() const
        {
            return _nodeName;
        }

        int size() const
        {
            return _st.st_size;
        }

        string getPath() const
        {
            return stringPath;
        }
        
        virtual string find(string nodeName)
        {
           
        }

        virtual int infoContent() const
        {
            return size();
        }

        virtual void add(Node *node)
        {
            throw string("unable to add");
        }

        virtual int numberOfChildren() const
        {
            throw string("number of children: not applicable");
        }

        virtual string classType() const
        {

        }

    private:
        const char *_path;
        struct stat _st;
        string _nodeName;
        string stringPath;

        string getName() const
        {
            for (int i = stringPath.size(); i > 0; i--)
            {
                if (stringPath[i]=='/') return stringPath.substr(i+1, stringPath.size());
            }

        }

        string charPointerToString() const
        {
            char *fileName = (char*)malloc(sizeof(_path));
            strcpy(fileName, _path);
            string str(fileName);

            return str;
        }
};
#endif
