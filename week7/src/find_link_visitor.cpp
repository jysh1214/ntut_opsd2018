#include "find_link_visitor.h"
#include "file.h"
#include "folder.h"
#include "link.h"

FindLinkVisitor::FindLinkVisitor()
{
}

void FindLinkVisitor::visitFile(File *file)
{
}

void FindLinkVisitor::visitFolder(Folder *folder)
{
    NodeIterator *it = folder->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
        it->currentItem()->accept(this);
    }
}

void FindLinkVisitor::visitLink(Link *link)
{
    _links.push_back(link);
}
