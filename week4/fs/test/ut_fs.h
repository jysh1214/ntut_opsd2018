#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>

/*
test_data
    \u251c\u2500\u2500 folder
    \u2502?   \u2514\u2500\u2500 a.out
    \u2514\u2500\u2500 hello.cpp
*/

TEST (FileSystemTest, nodeName)
{
    Node * test_data = new Folder ("./test_data");
    ASSERT_EQ("test_data", test_data->name());

    Node * folder = new Folder ("./test_data/folder");
    ASSERT_EQ("folder", folder->name());

    Node * hello_cpp = new File ("./test_data/hello.cpp");
    ASSERT_EQ("hello.cpp", hello_cpp->name());

    Node * a_out = new Folder ("./test_data/folder/a.out");
    ASSERT_EQ("a.out", a_out->name());
}

TEST (FileSystemTest, findNode)
{
    Node * a_out = new File ("./test_data/folder/a.out");
    ASSERT_EQ("a.out", a_out->find("a.out"));

    Node * test_data = new Folder ("./test_data");
    Node * hello_cpp = new File ("./test_data/hello.cpp");
    test_data->add(hello_cpp);
    ASSERT_EQ("test_data/hello.cpp", test_data->find("hello.cpp")); 
}

/*
TEST (MiscTest, lstatOnFolder)
{
    const char * path = "./test_data";
    struct stat st;
    ASSERT_EQ(0, lstat(path, &st));
    ASSERT_EQ(128, st.st_size);
    ASSERT_EQ(true, S_ISDIR(st.st_mode));
    ASSERT_EQ(false, S_ISREG(st.st_mode));
    ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST (FileSystemTest, Size)
{
    Node * test_data = new Folder ("./test_data");
    ASSERT_EQ(128,test_data->size());
    Node * folder = new Folder("./test_data/folder");
    ASSERT_EQ(96, folder->size());
    Node * hello_cpp = new File("./test_data/hello.cpp");
    ASSERT_EQ(83, hello_cpp->size());
    Node * a_out = new File("./test_data/folder/a.out");
    ASSERT_EQ(8432, a_out->size());
    test_data->add(folder);
    test_data->add(hello_cpp);
    ASSERT_EQ(2,test_data->numberOfChildren());
}

TEST (FileSystemTest, InfoContent)
{
    Node * a_out = new File("./test_data/folder/a.out");
    ASSERT_EQ(8432, a_out->infoContent());
    Node * hello_cpp = new File("./test_data/hello.cpp");
    ASSERT_EQ(83, hello_cpp->infoContent());
    Node * folder = new Folder("./test_data/folder");
    folder->add(a_out);
    ASSERT_EQ(8432, folder->infoContent());
    Node * test_data = new Folder("./test_data");
    test_data->add(folder);
    test_data->add(hello_cpp);
    ASSERT_EQ(8515, test_data->infoContent());
}

TEST (FileSystemTest, Visitor)
{
    Node * a_out = new File("./test_data/folder/a.out");
    // InfoContentVisitor icv = new InfoContentVisitor();
}
*/
#endif
