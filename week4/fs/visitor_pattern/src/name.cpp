#include <string>
#include "name.h"
#include "node.h"
#include "file.h"
#include "folder.h"

Name::Name()
{

}

string Name::visitFile(File *file)
{
    // return file->name();
    string nodeName;
    string tempStr = file->_path;
    nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));

    return nodeName;
}

string Name::visitFolder(Folder *folder)
{
    // return folder->name();
    string nodeName;
    string tempStr = folder->_path;
    nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));

    return nodeName;
}
