#ifndef FILE_H
#define FILE_H

#include "node.h"

class File: public Node
{
    public:
        
        File(const char *path): Node(path) 
        {
        	
        }

        string classType() const
        {
        	return "File";
        }
};
#endif
