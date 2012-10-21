CC=gcc
LIB=..

LIB_MAP=$(LIB)/map.c
LIB_LIST=$(LIB)/list.c


mapper:
	$(CC) $(LIB_MAP) $(LIB_LIST) mapper.c -o mapper -g

clean-mapper:
	rm -f mapper

logger:
	$(CC) logger.c -o logger -g

clean-logger:
	rm -f logger

lister:
	$(CC) $(LIB_LIST) lister.c -o lister -g

clean-lister:
	rm -f lister

all: mapper logger lister

clean: clean-mapper \
	clean-logger	\
	clean-lister
