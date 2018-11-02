#include <memory>
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
    
    NodeIterator * it = folder->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
        it->currentItem()->accept(this);
    }
}
