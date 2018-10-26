#ifndef UT_FS_H
#define UT_FS_H

#include <iostream>

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/action.h"
#include "../src/name.h"
#include "../src/find.h"
#include "../src/infocontent.h"

using namespace::std;

TEST (VisitorPatternTest, name_1)
{
    Node * test_data = new Folder ("./test_data");
    Action * n = new Name();
    test_data->accept(n);
    n->getName();
    ASSERT_EQ("test_data", n->getName());
}

TEST (VisitorPatternTest, name_2)
{
    Node * test_data = new Folder ("./test_data");
    Action * n = new Name();
    test_data->accept(n);
    ASSERT_EQ("test_data", n->getName());
}

TEST (VisitorPatternTest, name_3)
{
    Node * file_h = new File("./src/file.h");
    Action * n = new Name();
    file_h->accept(n);
    ASSERT_EQ("file.h", n->getName());
}

TEST (VisitorPatternTest, find_1)
{
    Node * hello_cpp = new File ("./test_data/hello.cpp");
    Action * f = new Find("hello.cpp");
    hello_cpp->accept(f);
    ASSERT_EQ("hello.cpp", f->findResult());
}

TEST (VisitorPatternTest, find_2)
{
    Node * test_data = new Folder ("./test_data");
    Action * f = new Find("a.out");
    test_data->accept(f);
    ASSERT_EQ("", f->findResult());
}

TEST (FindFileTest, FileSearchItsSelf)
{
    Node * a_out = new File("./test_data/folder/a.out");
    Action * f = new Find("a.out");
    a_out->accept(f);
    ASSERT_EQ("a.out", f->findResult());
}

TEST (FindFileTest, FileSearchNotItsSelf)
{
    Node * a_out = new File("./test_data/folder/a.out");
    Action * f = new Find("b.out");
    a_out->accept(f);
    ASSERT_EQ("", f->findResult());
}

TEST (FindFolderTest, FolderSearchItsSelf)
{
    Node * folder = new Folder("./test_data/folder");
    Action * f = new Find("folder");
    folder->accept(f);
    ASSERT_EQ("", f->findResult());
}

TEST (FindFolderTest, FolderSearchNotItsSelf)
{
    Node * test_data = new Folder("./test_data");
    Node * folder = new Folder("./test_data/folder");
    Action * f = new Find("test_data");
    folder->accept(f);
    ASSERT_EQ("", f->findResult());
}

TEST (FindFileNodeNameTest, SearchFileInFolder)
{
    Node * folder = new Folder("./test_data/folder");
    Node * a_out = new File("./test_data/folder/a.out");
    folder->add(a_out);
    Action * f = new Find("a.out");
    folder->accept(f);
    ASSERT_EQ("./a.out", f->findResult());
}

TEST (FindFolderNodeNameTest, SearchFolderInFolder)
{
    Node * test_data = new Folder ("./test_data");
    Node * folder = new Folder("./test_data/folder");
    test_data->add(folder);
    Action * f = new Find("folder");
    test_data->accept(f);
    ASSERT_EQ("./folder", f->findResult());
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

    Action * f = new Find("hello.cpp");
    test_data->accept(f);
    ASSERT_EQ("./folder/hello.cpp\n./hello.cpp", f->findResult());
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

    Action * f = new Find("hello.cpp");
    folder->accept(f);
    ASSERT_EQ("./hello.cpp", f->findResult());
}

TEST (InfoContentTest, InfoContent)
{
    std::vector<Node *> children;
    Node * test_data = new Folder("./test_data");
    Node * folder = new Folder("./test_data/folder");
    Node * hello_cpp1 = new File("./test_data/folder/hello.cpp");
    Node * hello_cpp2 = new File("./test_data/hello.cpp");

    folder->add(hello_cpp1);
    test_data->add(folder);
    test_data->add(hello_cpp2);

    Action * i = new InfoContent();
    folder->accept(i);
    ASSERT_EQ(85, i->getContentSize());       
}
#endif
