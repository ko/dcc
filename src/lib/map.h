#ifndef __MAP_H__
#define __MAP_H__

struct map_val_t {
    char * k;
    int v;
    struct map_val_t * next;
}

struct map_t {
    int size;
    struct map_val_t * next
};


struct map_t * map_init(void);

int map_size(void * map);
int map_is_empty(void * map);

int map_put(void * map, char * key, int value);
int map_get(void * map, char * key, int * value);
int map_remove(void * map, char * key);

#endif
