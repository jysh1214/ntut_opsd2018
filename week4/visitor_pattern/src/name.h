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
        string visitFile(File *file);
        string visitFolder(Folder *folder);
};

#endif
