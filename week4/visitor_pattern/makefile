.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/ut_fs

$(BIN)/ut_fs: $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(SRC)/node.h $(SRC)/folder.h $(SRC)/file.h $(OBJ)/action.o $(OBJ)/name.o $(OBJ)/find.o
	g++ -std=c++11 $< $(OBJ)/action.o $(OBJ)/name.o $(OBJ)/find.o -o $@ $(LIBS)

$(OBJ)/action.o: $(SRC)/action.cpp $(SRC)/action.h
	g++ -std=c++11 -c $< -o $@

$(OBJ)/name.o: $(SRC)/name.cpp $(SRC)/name.h
	g++ -std=c++11 -c $< -o $@

$(OBJ)/find.o: $(SRC)/find.cpp $(SRC)/find.h
	g++ -std=c++11 -c $< -o $@	

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
