.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/hw5

$(BIN)/hw5: $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(SRC)/node.h $(SRC)/folder.h $(SRC)/file.h $(SRC)/node_visitor.h $(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o
	g++ -g -Wall -std=c++11 $< $(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o -o $@ $(LIBS)

$(OBJ)/find_visitor.o: $(SRC)/find_visitor.cpp $(SRC)/find_visitor.h
	g++ -g -Wall -std=c++11 -c $< -o $@

$(OBJ)/info_content_visitor.o: $(SRC)/info_content_visitor.cpp $(SRC)/info_content_visitor.h
	g++ -g -Wall -std=c++11 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
