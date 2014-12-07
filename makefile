CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)
MAIN_OBJECTS := $(patsubst $(SRC)/mains/%.cpp, $(OBJ)/%.o, $(wildcard $(SRC)/mains/*.cpp))

all: $(BIN)/translator $(BIN)/reverse $(BIN)/compose $(BIN)/intersection

dummy:
	echo $(MAIN_OBJECTS);

$(BIN)/translator: $(OBJECTS) $(OBJ)/translator.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/reverse: $(OBJECTS) $(OBJ)/reverse.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/compose: $(OBJECTS) $(OBJ)/compose.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/intersection: $(OBJECTS) $(OBJ)/intersection.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(MAIN_OBJECTS): $(OBJ)/%.o: $(SRC)/mains/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

doc:
	doxygen $(DOC)/doxys/Doxyfile

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc
