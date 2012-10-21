SRC_ROOT=..
LIB=$(SRC_ROOT)/lib

# Libraries
SRC=$(LIB)/map.c \
	$(LIB)/list.c 

# Dependencies
SRC += init.c

SRC += lexical.c
OBJ=lexi

all:
	gcc $(SRC) -o $(OBJ) -I$(LIB)

clean:
	rm $(OBJ)
