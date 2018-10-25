#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/action.h"
#include "../src/name.h"
#include "../src/find.h"

TEST (VisitorPatternTest, name_1)
{
    Node * test_data = new Folder ("./test_data");
    Action * n = new Name();
    ASSERT_EQ("test_data", test_data->accept(n));
}

TEST (VisitorPatternTest, name_2)
{
    Node * test_data = new Folder ("./test_data");
    Action * n = new Name();
    ASSERT_EQ("test_data", test_data->accept(n));
}

TEST (VisitorPatternTest, name_3)
{
    Node * file_h = new File("./src/file.h");
    Action * n = new Name();
    ASSERT_EQ("file.h", file_h->accept(n));
}

TEST (VisitorPatternTest, find_1)
{
    Node * hello_cpp = new File ("./test_data/hello.cpp");
    Action * f = new Find("hello.cpp");
    ASSERT_EQ("hello.cpp", hello_cpp->accept(f));
}

TEST (VisitorPatternTest, find_2)
{
    Node * test_data = new Folder ("./test_data");
    Action * f = new Find("a.out");
    ASSERT_EQ("", test_data->accept(f));
}

// TEST (FindFileTest, FileSearchItsSelf)
// {
//   Node * a_out = new File("./test_data/folder/a.out");
//   ASSERT_EQ("a.out", a_out->find("a.out"));
// }

// TEST (FindFileTest, FileSearchNotItsSelf)
// {
//   Node * a_out = new File("./test_data/folder/a.out");
//   ASSERT_EQ("", a_out->find("b.out"));
// }

// TEST (FindFolderTest, FolderSearchItsSelf)
// {
//   Node * folder = new Folder("./test_data/folder");
//   ASSERT_EQ("",folder->find("folder"));
// }

// TEST (FindFolderTest, FolderSearchNotItsSelf)
// {
//   Node * test_data = new Folder("./test_data");
//   Node * folder = new Folder("./test_data/folder");
//   ASSERT_EQ("",folder->find("test_data"));
// }

// TEST (FindFileNodeNameTest, SearchFileInFolder)
// {
//   Node * folder = new Folder("./test_data/folder");
//   Node * a_out = new File("./test_data/folder/a.out");
//   folder->add(a_out);
//   ASSERT_EQ("./a.out",folder->find("a.out"));
// }

// TEST (FindFolderNodeNameTest, SearchFolderInFolder)
// {
//   Node * test_data = new Folder ("./test_data");
//   Node * folder = new Folder("./test_data/folder");
//   test_data->add(folder);
//   ASSERT_EQ("./folder",test_data->find("folder"));
// }

// TEST (FindNodeNameTest, test_data)
// {
//   std::vector<Node *> children;
//   Node * test_data = new Folder("./test_data");
//   Node * folder = new Folder("./test_data/folder");
//   Node * hello_cpp1 = new File("./test_data/folder/hello.cpp");
//   Node * hello_cpp2 = new File("./test_data/hello.cpp");

//   folder->add(hello_cpp1);
//   test_data->add(folder);
//   test_data->add(hello_cpp2);

//   ASSERT_EQ("./folder/hello.cpp\n./hello.cpp", test_data->find("hello.cpp"));
// }

// TEST (FindNodeNameTest, folder)
// {
//   std::vector<Node *> children;
//   Node * test_data = new Folder("./test_data");
//   Node * folder = new Folder("./test_data/folder");
//   Node * hello_cpp1 = new File("./test_data/folder/hello.cpp");
//   Node * hello_cpp2 = new File("./test_data/hello.cpp");

//   folder->add(hello_cpp1);
//   test_data->add(folder);
//   test_data->add(hello_cpp2);

//   ASSERT_EQ("./hello.cpp", folder->find("hello.cpp"));
// }

#endif
