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
        
        virtual string find(string nodeName)
        {
            if (_nodeName==nodeName) return nodeName;
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

    protected:
        const char *_path;
        struct stat _st;
        string _nodeName;

        string getName() const
        {
            char *fileName = (char*)malloc(sizeof(_path));
            strcpy(fileName, _path);
            /*
            char *next;

            while ((next = strchr(fileName, '/')))
            {
                fileName = next + 1;
            }

            string str(fileName); //convert char * to string
            return str;
            */
            string str(fileName); //convert char * to string
            //free(fileName);
            for (int i = str.size(); i > 0; i--)
            {
                if (str[i]=='/') return str.substr(i+1, str.size());
            }

        }
};
#endif
