#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"

TEST (MiscTest, lstatOnFolder)
{
  const char * path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(4096, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST (FolderSystemTest, Name)
{
  Node * test_data = new Folder ("./test_data");
  ASSERT_EQ("test_data", test_data->name());
}

TEST (FileSystemTest, Name)
{
  Node * file_h = new File("./src/file.h");
  ASSERT_EQ("file.h", file_h->name());
}

TEST (FindFileTest, FileSearchItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("a.out", a_out->find("a.out"));
}

TEST (FindFileTest, FileSearchNotItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("", a_out->find("b.out"));
}

TEST (FindFolderTest, FolderSearchItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("folder"));
}

TEST (FindFolderTest, FolderSearchNotItsSelf)
{
  Node * test_data = new Folder("./test_data");
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("test_data"));
}

TEST (FindFileNodeNameTest, SearchFileInFolder)
{
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  folder->add(a_out);
  ASSERT_EQ("./a.out",folder->find("a.out"));
}

TEST (FindFolderNodeNameTest, SearchFolderInFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  ASSERT_EQ("./folder",test_data->find("folder"));
}

TEST (FindNodeNameTest, test_data)
{
  std::vector<Node *> children;
  Node * test_data = new Folder("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * hello_cpp1 = new File("./test_data/folder/hello.cpp");
  Node * hello_cpp2 = new File("./test_data/hello.cpp");

  folder->add(hello_cpp1);
  test_data->add(folder);
  test_data->add(hello_cpp2);

  ASSERT_EQ("./folder/hello.cpp\n./hello.cpp", test_data->find("hello.cpp"));
}

TEST (FindNodeNameTest, folder)
{
  std::vector<Node *> children;
  Node * test_data = new Folder("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * hello_cpp1 = new File("./test_data/folder/hello.cpp");
  Node * hello_cpp2 = new File("./test_data/hello.cpp");

  folder->add(hello_cpp1);
  test_data->add(folder);
  test_data->add(hello_cpp2);

  ASSERT_EQ("./hello.cpp", folder->find("hello.cpp"));
}

// TEST (FolderSystemTest, Name)
// {
//   Node * folder = new Folder("./test_data/folder");
//   ASSERT_EQ(96, folder->size());
//   Node * hello_cpp = new File("./test_data/hello.cpp");
//   ASSERT_EQ(83, hello_cpp->size());
//   Node * a_out = new File("./test_data/folder/a.out");
//   ASSERT_EQ(8432, a_out->size());
//   test_data->add(folder);
//   test_data->add(hello_cpp);
//   ASSERT_EQ(2,test_data->numberOfChildren());
// }

// TEST (FileSystemTest, InfoContent)
// {
//   Node * a_out = new File("./test_data/folder/a.out");
//   ASSERT_EQ(8432, a_out->infoContent());
//   Node * hello_cpp = new File("./test_data/hello.cpp");
//   ASSERT_EQ(83, hello_cpp->infoContent());
//   Node * folder = new Folder("./test_data/folder");
//   folder->add(a_out);
//   ASSERT_EQ(8432, folder->infoContent());
//   Node * test_data = new Folder("./test_data");
//   test_data->add(folder);
//   test_data->add(hello_cpp);
//   ASSERT_EQ(8515, test_data->infoContent());
// }

// TEST (FileSystemTest, Visitor)
// {
//   Node * a_out = new File("./test_data/folder/a.out");
//   // InfoContentVisitor icv = new InfoContentVisitor();
// }

#endif
