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

struct list_t * list_init(void);
int list_deinit(struct list_t * list);

int list_size(struct list_t *list);
int list_is_empty(struct list_t *list);

int list_insert(struct list_t *list, char *key, int value);
int list_lookup(struct list_t *list, char *key, int *value);
int list_remove(struct list_t *list, char *key);
int list_contain(struct list_t *list, char *key, int *found);

#endif
