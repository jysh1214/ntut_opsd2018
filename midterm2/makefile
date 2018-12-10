.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/midterm2

$(BIN)/midterm2: $(TEST)/ut_test.cpp $(TEST)/ut_test.h $(OBJ)/triangle.o $(OBJ)/triangle_factory.o $(SRC)/obj.h $(OBJ)/set.o $(OBJ)/int.o
	g++ -Wall -g -std=c++11 $< $(OBJ)/triangle.o $(OBJ)/triangle_factory.o $(OBJ)/set.o $(OBJ)/int.o -o $@ $(LIBS)

$(OBJ)/triangle.o: $(SRC)/triangle.cpp $(SRC)/triangle.h
	g++ -Wall -std=c++11 -c $< -o $@

$(OBJ)/triangle_factory.o: $(SRC)/triangle_factory.cpp $(SRC)/triangle_factory.h
	g++ -Wall -std=c++11 -c $< -o $@

$(OBJ)/set.o: $(SRC)/set.cpp $(SRC)/set.h
	g++ -Wall -std=c++11 -c $< -o $@

$(OBJ)/int.o: $(SRC)/int.cpp $(SRC)/int.h
	g++ -Wall -std=c++11 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
