# Pattern Oriented Software Design
#### Fall, 2018
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

#### Homework 5

# Purpose of the homework:

####  Use the [course material](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2018f) to implement Visitor Pattern.

####  Change the data structure `std::vector<Node *>`  into `std::map<string, Node *>` and refactor related member functions.
# Requirements:
 1. Make sure your project structure is the same as [course project directory](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2018f).
 2. In Folder class, you must change the the data structure `std::vector<Node *>` into `std::map<string,Node *>` and make sure member functions in Folder class work correctly afterwards. 
   
    **Note:** You must use filename as your key in `std::map<string, Node *>`

 3. Create the NodeVisitor class in node_visitor.h, and NodeVisitor class is represented as a Visitor in Visitor pattern.

        class NodeVisitor
        {
          public:
              virtual void visitFolder() = 0;
              virtual void visitFile() = 0;
        };

 4. Create the FindVisitor in find_visitor.h and find_visitor.cpp. Implement an operation to find file or folder by filename and return its relative path. 

        class FindVisitor
        {
            public:
                FindVisitor(std::string name);
                void visitFolder();
                void visitFile();
                std::string findResult();//return relative path which are found by name.
        };

 5. In order to achieve the polymorphism in `accept(NodeVisitor *)`, you have to make InfoContentVisitor class and FindVisitor class inherit NodeVisitor class.

 6. Create NullIterator in null_iterator.h, where the member function `isDone()` must return true. 
    
    **Note:** The File class call createIterator() must return NullIterator.

        class NullIterator:public NodeIterator
        {
          public:
            void first(){
              //definition by yourself
            }
            Node* currentItem(){
              //definition by yourself
            }
            void next() {
              //definition by yourself  
            }
            bool isDone(){
              return true;
            }
        };



# Grading rubrics

TA assigned 10 test cases in CI. Each test is 10 points.

# Note
Make sure your all tests pass on your local machine. Then you can push to Gitlab and see the report on Jenkins.
