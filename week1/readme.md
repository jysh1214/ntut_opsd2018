## Week 1

- Simple tooling
  - Atom, g++, make, git
- Organizing project directory: We will work with projects with many files
  - From:
```
  hello.cpp a.out
```
  - To:
```
  src/hello.cpp      // folder for production code
  bin/hello          // folder for executables
  test/              // folder for test code
  obj/               // folder for object code
  makefile
  readme.md // project info
```
- makefile objectives:
  - maintaining project structure
  - enabling recompilation when dependent files changes
  - actions:
    - compile
    - link
    - cleanup
    - statistics
- jenkins/gitlab/googletest

## Getting started with Google Test (GTest) on Ubuntu
```
sudo apt-get install libgtest-dev
```
```
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
```
```
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```

## Tasks for problem 1
- Take care of command line parameters
- Select sorting algorithm
- Representation of Shapes

compiling:

g++ ut_shape.cpp -o ut_shape -lgtest -lpthread

reference:
https://stackoverflow.com/questions/32428595/gtest-test-compiling-error/32428714


