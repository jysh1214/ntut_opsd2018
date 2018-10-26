#include <string>
#include "name.h"
#include "node.h"
#include "file.h"
#include "folder.h"

Name::Name()
{

}

void Name::visitFile(File *file)
{
    string tempStr = file->_path;
    _name = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));
}

void Name::visitFolder(Folder *folder)
{
    string tempStr = folder->_path;
    _name = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));
}
