# Pattern Oriented Software Design
#### Fall, 2018
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

#### Homework 7

# Purpose of the homework
####  Implement FindNodeByPathnameVisitor.

# Requirements
 1. Make sure your project structure is the same as course project directory.

 2. Create the FindNodeByPathnameVisitor class in find_node_by_pathname_visitor.h and find_node_by_pathname_visitor.cpp. Implement an operation to find Node by path and use getNode() to get the Node.


        Class FindNodeByPathnameVisitor{
          public:
              FindNodeByPathnameVisitor(std::vector<string>* pathnames){}
              void visitFolder(Folder * folder);
              void visitFile(File * file);
              void visitLink(Link * link);
              Node * getNode() const; //
              return the Node object if the path indicate the node in the file system, and if not, return nullptr.
        }

       Example test cases(using course test_data folder):

        TEST (FindNodeByPathnameVisitor, Link){
              Node * hello = new Link("./test_data/hello");
              std::vector<std::string>* names = new std::vector<std::string>{std::string("hello")};
              FindNodeByPathnameVisitor fv(names);
              hello->accept(fv);
              ASSERT_EQ(hello, fv.getNode());
        }
        TEST (FindNodeByPathnameVisitor, LinkInFolder){
              Node * test_data = new Folder ("./test_data");
              Node * hello = new Link("./test_data/hello");
              test_data->add(hello);
              std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("hello")};
              FindNodeByPathnameVisitor fv(names);
              test_data->accept(fv);
              ASSERT_EQ(hello, fv.getNode());
        }
        TEST (FindNodeByPathnameVisitor, nonExistingFileInFileSystem){
              Node * test_data = new Folder ("./test_data");
              std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("helloWorld")};
              FindNodeByPathnameVisitor fv(names);
              test_data->accept(fv);
              ASSERT_EQ(nullptr, fv.getNode());
        }

 3.  Implement `getParent()` and `setParent()` member function in Node class.

     Note: The default parent node is nullptr, and you will set the parent node when the node is added in the folder.

         Node * getParent() const{

         }
         void setParent (Node * p){

         }

 4. Write the corresponding makefile to generate executable file which named `hw7` in bin folder.
