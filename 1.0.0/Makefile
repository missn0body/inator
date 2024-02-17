# Simply replace CC with your own compiler
# if it doesn't match the ones listed below.

#CC = i586-pc-msdosdjgpp-g++
#CC = i686-w64-mingw32-g++
#CC = x86_64-w64-mingw32-g++
CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g -std=c++2b -Ofast
RM = rm

BDIR = bin
ODIR = obj
SDIR = src

SOURCE = $(shell find src/*.cpp -printf "%f ")

# Update this line to change the name of target executable
TARGET = inator

BIN = $(TARGET:%=$(BDIR)/%)
OBJ = $(SOURCE:%.cpp=$(ODIR)/%.o)

.PHONY: all clean
all: $(BIN)
clean:
	$(RM) -f $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJ): $(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)
