.PHONY: clean dirs

BIN=bin
SRC=src
OBJ=obj
LIBS=`wx-config --libs`
CXXFLAGS=`wx-config --cxxflags`

all: dirs $(BIN)/hw8

$(BIN)/hw8: $(SRC)/main.cpp $(SRC)/main.h $(OBJ)/frame.o\
            $(SRC)/node.h $(SRC)/folder.h $(SRC)/file.h $(SRC)/link.h $(SRC)/node_builder.h | $(BIN)
	g++ -Wall -std=c++11 $< $(OBJ)/frame.o $(LIBS) $(CXXFLAGS) -o $@

$(OBJ)/frame.o: $(SRC)/frame.cpp $(SRC)/frame.h | $(OBJ)
	g++ -Wall -std=c++11 -c $< -o $@ $(CXXFLAGS)

dirs:
	mkdir -p $(SRC) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
