#include "infocontent.h"
#include "node.h"
#include "file.h"
#include "folder.h"

InfoContent::InfoContent(): _size(0)
{

}

void InfoContent::visitFile(File *file)
{
    _size += file->size();
}

void InfoContent::visitFolder(Folder *folder)
{
    for (int i = 0; i < folder->numberOfChildren(); i++)
    {
        (folder->getChildren())[i]->accept(this);
    }
}
