#ifndef __LIST_H__
#define __LIST_H__

#define KEY_MAX_SIZE 128

#include <inttypes.h>

struct node_t {
    char k[KEY_MAX_SIZE];
    int v;
    struct node_t * next;
};

struct list_t {
    uint32_t size;
    struct node_t *head;
};


void free_it_all(struct node_t * node);


struct list_t * list_init(void);
void list_deinit(void * list);

int list_size(void * list);
int list_is_empty(void * list);

int list_insert(void * list, char *key, int value);
int list_lookup(void * list, char *key, int *value);
int list_remove(void * list, char *key);
int list_contain(void * list, char *key, int *found);

#endif
