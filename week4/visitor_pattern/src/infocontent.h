#ifndef INFOCONTENT_H
#define INFOCONTENT_H

#include "action.h"

class File;
class Folder;

using namespace::std;

class InfoContent: public Action
{
    public:
        InfoContent();
        void visitFile(File *file);
        void visitFolder(Folder *folder);

        int getContentSize() const
        {
            return _size;
        }

    private:
        int _size;
};
#endif
