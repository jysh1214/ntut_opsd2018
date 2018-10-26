#ifndef ACTION_H
#define ACTION_H

#include <string>

class File;
class Folder;

using namespace::std;

class Action
{
    public:
        Action();
        virtual void visitFile(File *file) = 0;
        virtual void visitFolder(Folder *folder) = 0;

        virtual string getName();
        virtual string findResult();
        virtual int getContentSize();
};
#endif
