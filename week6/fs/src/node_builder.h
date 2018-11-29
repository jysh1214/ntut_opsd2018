#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H

#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include <vector>

#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"

#include <iostream>
using namespace std;

class NodeBuilder
{
public:
  NodeBuilder() {}

  void build(const char *path)
  {
    struct stat st;
    if (lstat(path, &st) == 0)
    {
      if (S_ISREG(st.st_mode))
        _root = new File(path);

      else if (S_ISLNK(st.st_mode))
        _root = new Link(path);

      else if (S_ISDIR(st.st_mode))
      {
        _root = new Folder(path);
        DIR *dir = opendir(path);

        if (dir == nullptr)
          throw std::string("open folder error");

        struct dirent *entry = nullptr;
        while ((entry = readdir(dir)) != nullptr)
        {
          if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..")
          {
            NodeBuilder nb;
            // const char *pathName = (std::string(path) + "/" + entry->d_name).c_str();
            // nb.build(pathName);
            std::string pathName = std::string(path) + "/" + std::string(entry->d_name);
            nb.build(pathName.c_str());
            _root->add(nb.getRoot());
          }
        }
      }
    }
  }

  // std::vector<Node *> getLink()
  // {
  //   NodeVisitor *nodeVisitor = new FindLinkVisitor();
  //   _root->accept(nodeVisitor);
  //   _symLinks = nodeVisitor->getLinks();
  //   return _symLinks;  
  // }

  // Node *getSource()
  // {
  //   char buf[1024];
  //   ssize_t len;
  //   for(int i = 0; i < _symLinks.size(); i++)
  //   {
  //     if ((len = readlink((_symLinks[i]->getPath()).c_str(), buf, sizeof(buf)-1)) != -1)
  //       buf[len] = '\0';
  //   }
  //   cout << buf << endl;
  //   std::string buff;
  //   buff = _root->getPath() + "/";
  //   std::string s(buf);
  //   buff = buff + s;
  //   cout << buff << endl;
  //    const char* cpc = buff.c_str();
  //   _source = new File(cpc);
  //   return _source;
  // }

  Node *getRoot()
  {
    return _root;
  }

private:
  Node *_root;
  Node *_source;
  std::vector<Node *> _symLinks;
};

#endif
