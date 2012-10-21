#ifndef __LIST_H__
#define __LIST_H__

#define KEY_MAX_SIZE 128

#include <inttypes.h>

typedef struct node_s {
    char k[KEY_MAX_SIZE];
    int v;
    struct node_s * next;
} node_t;

typedef struct list_s {
    uint32_t size;
    struct node_s *head;
} list_t;


void free_it_all(node_t * node);


list_t * list_init(void);
void list_deinit(void * list);

int list_size(void * list);
int list_is_empty(void * list);

void list_insert(void * list, char *key, int value);
int list_lookup(void * list, char *key, int *value);
int list_remove(void * list, char *key);
int list_contain(void * list, char *key, int *found);

#endif
