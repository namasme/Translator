CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)


all: $(BIN)/trans
	
$(BIN)/trans: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

doc:
	doxygen $(DOC)/doxys/Doxyfile

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc
