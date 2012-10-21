SRC_ROOT=..
LIB=$(SRC_ROOT)/lib
SRC=$(LIB)/map.c \
	$(LIB)/list.c 

SRC += lexical.c
OBJ=lexical

all:
	gcc $(SRC) -o $(OBJ) -I$(LIB)

clean:
	rm $(OBJ)
