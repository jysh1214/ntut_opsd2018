#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include <iostream>
#include <memory>

#include "../src/folder.h"
#include "../src/file.h"
#include "../src/link.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/find_link_visitor.h"
#include "../src/node_iterator.h"
#include "../src/node_builder.h"
#include "../src/find_node_by_pathname_visitor.h"

TEST(MiscTest, lstatOnFolder)
{
  const char *path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(4096, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}
// TEST(MiscTest, TryCatch)
// {
//   Node *hello_cpp1 = new File("./test_data/folder/hello.cpp");
//   Node *hello_cpp2 = new File("./test_data/hello.cpp");
//   Node *test_data = new Folder("./test_data");
//   Node *folder = new Folder("./test_data/folder");
//   std::string line = "";
//   test_data->add(hello_cpp2);

//   try
//   {
//     if (test_data->numberOfChildren())
//     {
//     }
//     ASSERT_EQ("", line);
//   }
//   catch (std::string line)
//   {
//     ASSERT_EQ("number of children: not applicable\n", line);
//   }
// }

class FileSystemTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    test_data = new Folder("./test_data");
    folder = new Folder("./test_data/folder");
    hello_cpp = new File("./test_data/hello.cpp");
    a_out = new File("./test_data/folder/a.out");
    hello = new Link("./test_data/hello", a_out);
    hello_cpp2 = new File("./test_data/folder/hello.cpp");
    
    folder->add(a_out);
    folder->add(hello_cpp2);
    test_data->add(folder);
    test_data->add(hello);
    test_data->add(hello_cpp);
  }

  void TearDown() override
  {
    delete hello_cpp2;
    delete a_out;
    delete hello_cpp;
    delete hello;
    delete folder;
    delete test_data;
  }

  Node *test_data;
  Node *folder;
  Node *hello_cpp;
  Node *a_out;
  Node *hello;
  Node *hello_cpp2;
};

TEST_F (FileSystemTest, Size)
{
  ASSERT_EQ(4096,test_data->size());
  ASSERT_EQ(4096, folder->size());
  ASSERT_EQ(14, hello->size());
  ASSERT_EQ(85, hello_cpp->size());

  ASSERT_EQ(8608, a_out->size());
  ASSERT_EQ(8608, dynamic_cast<Link *>(hello)->getSource()->size());
  
}

TEST_F (FileSystemTest, NumberOfChildren)
{
  ASSERT_EQ(3, test_data->numberOfChildren());
  ASSERT_EQ(2, folder->numberOfChildren());
}

TEST_F (FileSystemTest, Name)
{
  ASSERT_EQ("test_data", test_data->name());
  ASSERT_EQ("folder", folder->name());
  ASSERT_EQ("hello.cpp", hello_cpp->name());
  ASSERT_EQ("a.out", a_out->name());
  ASSERT_EQ("hello", hello->name());
  ASSERT_EQ("hello.cpp", hello_cpp2->name());
}

TEST_F (FileSystemTest, InfoContentVisitor_a_out)
{
  NodeVisitor * icv = new InfoContentVisitor();
  a_out->accept(icv);
  ASSERT_EQ(8608, icv->getContentSize());
  delete icv;
}
TEST_F (FileSystemTest, InfoContentVisitor_hello)
{
  NodeVisitor * icv = new InfoContentVisitor();
  hello->accept(icv);
  ASSERT_EQ(8608, icv->getContentSize());
  delete icv;
}
TEST_F (FileSystemTest, InfoContentVisitor_folder)
{
  NodeVisitor * icv = new InfoContentVisitor();
  folder->accept(icv);
  ASSERT_EQ(8693, icv->getContentSize());
  delete icv;
}
TEST_F (FileSystemTest, InfoContentVisitor_hello_cpp)
{
  NodeVisitor * icv = new InfoContentVisitor();
  hello_cpp->accept(icv);
  ASSERT_EQ(85, icv->getContentSize());
  delete icv;
}
TEST_F (FileSystemTest, InfoContentVisitor_test_data)
{
  NodeVisitor * icv = new InfoContentVisitor();
  test_data->accept(icv);
  ASSERT_EQ(17386, icv->getContentSize());
  delete icv;
}

TEST_F (FileSystemTest, FindVisitor_hello_cpp)
{
  NodeVisitor *nodeVisitor = new FindVisitor("hello.cpp");
  hello_cpp->accept(nodeVisitor);
  ASSERT_EQ("hello.cpp", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, FindVisitor_a_out)
{
  NodeVisitor *nodeVisitor = new FindVisitor("a.out");
  a_out->accept(nodeVisitor);
  ASSERT_EQ("a.out", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, FindVisitor_empty)
{
  NodeVisitor *nodeVisitor = new FindVisitor("b.out");
  a_out->accept(nodeVisitor);
  ASSERT_EQ("", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, FindVisitor_empty2)
{
  NodeVisitor *nodeVisitor = new FindVisitor("folder");
  folder->accept(nodeVisitor);
  ASSERT_EQ("", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, FindVisitor_empty3)
{
  NodeVisitor *nodeVisitor = new FindVisitor("test_data");
  folder->accept(nodeVisitor);
  ASSERT_EQ("", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, SearchFileInFolder1)
{
  NodeVisitor *nodeVisitor = new FindVisitor("a.out");
  folder->accept(nodeVisitor);
  ASSERT_EQ("./a.out", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, SearchFileInFolder2)
{
  NodeVisitor *nodeVisitor = new FindVisitor("hello.cpp");
  folder->accept(nodeVisitor);
  ASSERT_EQ("./hello.cpp", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, SearchFolderInFolder)
{
  NodeVisitor *nodeVisitor = new FindVisitor("folder");
  test_data->accept(nodeVisitor);
  ASSERT_EQ("./folder", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, SearchRepeatFile)
{
  NodeVisitor *nodeVisitor = new FindVisitor("hello.cpp");
  test_data->accept(nodeVisitor);
  ASSERT_EQ("./folder/hello.cpp\n./hello.cpp", nodeVisitor->findResult());
  delete nodeVisitor;
}
TEST_F (FileSystemTest, SearchLink)
{
  NodeVisitor *nodeVisitor = new FindVisitor("hello");
  hello->accept(nodeVisitor);
  ASSERT_EQ("hello", nodeVisitor->findResult());
  delete nodeVisitor;
}

TEST_F (FileSystemTest,NodeIterator)
{
  std::unique_ptr<NodeIterator> it(test_data->createIterator());
  
  it->first();
  ASSERT_EQ(4096, it->currentItem()->size());
  it->next();
  ASSERT_EQ(14, it->currentItem()->size());
  it->next();
  ASSERT_EQ(85, it->currentItem()->size());
  it->next();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
}

TEST_F (FileSystemTest, NodeBuilderOnFile) 
{
  NodeBuilder nb;
  nb.build("test_data/hello.cpp");
  ASSERT_EQ(85, nb.getRoot()->size());

  nb.build("test_data/hello");
  ASSERT_EQ(14, nb.getRoot()->size());
  // ASSERT_EQ(8296, dynamic_cast<Link *>(nb.getRoot())->getSource()->size());

  //----------------------
  // NodeBuilder nb1;
  // nb1.build("test_data");
  // // ASSERT_ANY_THROW(nb1.getLink());
  // // ASSERT_EQ(8296, nb1.getSource()->size());
  //----------------------

  nb.build("test_data/folder");
  ASSERT_EQ(4096, nb.getRoot()->size());

  std::unique_ptr<NodeIterator> it(nb.getRoot()->createIterator());
  it->first();
  ASSERT_EQ(8608, it->currentItem()->size());   //test_data/folder/a.out
  it->next();
  ASSERT_EQ(85, it->currentItem()->size());      //test_data/folder/hello.cpp
  it->next();
  ASSERT_TRUE(it->isDone());

  nb.build("test_data");
  ASSERT_EQ(4096, nb.getRoot()->size());

  std::unique_ptr<NodeIterator> it1(nb.getRoot()->createIterator());
  it1->first();
  ASSERT_EQ(4096, it1->currentItem()->size());
  it1->next();
  ASSERT_EQ(14, it1->currentItem()->size());
  it1->next();
  ASSERT_EQ(85, it1->currentItem()->size());
  it1->next();
  ASSERT_TRUE(it1->isDone());
}

TEST_F (FileSystemTest, NodeBuilderOnLink) 
{
  NodeVisitor *nodeVisitor = new FindLinkVisitor();
  test_data->accept(nodeVisitor);
  
  // NodeBuilder nb;
  // nb.crossLink(nodeVisitor->getLinks());
  ASSERT_EQ(1, nodeVisitor->getLinks().size());
  delete nodeVisitor;
}

TEST_F (FileSystemTest, NodeTypeError)
{
  ASSERT_ANY_THROW(new File("./test_data/folder"));
  ASSERT_ANY_THROW(new Folder("./test_data/hello"));
  ASSERT_ANY_THROW(new Link("./test_data/hello.cpp"));
}

TEST(NodeBuilder, file)
{
  NodeBuilder nb;
  nb.build("makefile");
  ASSERT_EQ(918, nb.getRoot()->size());
}

// hw7
TEST (FindNodeByPathnameVisitor, Link){
      Node * hello = new Link("./test_data/hello");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("hello")};
      FindNodeByPathnameVisitor fv(names);
      // NodeVisitor * fv = new FindNodeByPathnameVisitor(names);
      hello->accept(fv);
      // ASSERT_EQ(hello, fv.getNode());
}
// TEST (FindNodeByPathnameVisitor, LinkInFolder){
//       Node * test_data = new Folder ("./test_data");
//       Node * hello = new Link("./test_data/hello");
//       test_data->add(hello);
//       std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("hello")};
//       FindNodeByPathnameVisitor fv(names);
//       test_data->accept(fv);
//       ASSERT_EQ(hello, fv.getNode());
// }
// TEST (FindNodeByPathnameVisitor, nonExistingFileInFileSystem){
//       Node * test_data = new Folder ("./test_data");
//       std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("helloWorld")};
//       FindNodeByPathnameVisitor fv(names);
//       test_data->accept(fv);
//       ASSERT_EQ(nullptr, fv.getNode());
// }


#endif
