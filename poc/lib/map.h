#ifndef __MAP_H__
#define __MAP_H__


#include "list.h"
typedef struct list_s map_t;



map_t * map_init(void);
void map_deinit(map_t * map);

int map_size(map_t * map);
int map_is_empty(map_t * map);

void map_put(map_t * map, char * key, int value);
int map_get(map_t * map, char * key, int * value);
int map_remove(map_t * map, char * key);

#endif
