CC=gcc
LIB=..

mapper:
	$(CC) mapper.c -o mapper -g

clean-mapper:
	rm -f mapper

logger:
	$(CC) logger.c -o logger -g

clean-logger:
	rm -f logger

lister:
	$(CC) $(LIB)/list.c lister.c -o lister -g

clean-lister:
	rm -f lister

all: mapper logger lister

clean: clean-mapper \
	clean-logger	\
	clean-lister
