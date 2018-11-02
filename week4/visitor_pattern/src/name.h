#ifndef NAME_H
#define NAME_H

#include "action.h"

class File;
class Folder;

using namespace::std;

class Name: public Action
{
    public:
        Name();
        void visitFile(File *file);
        void visitFolder(Folder *folder);
       
        string getName() const
        {
            return _name;
        }

    private:
        string _name;
};
#endif
