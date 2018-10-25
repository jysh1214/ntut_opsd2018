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

        virtual string visitFile(File *file);
        virtual string visitFolder(Folder *folder);
};

#endif
