#include <stdlib.h>
#include <string.h>

#include "list.h"

struct list_t * list_init(void)
{
    struct list_t * list;
    list = malloc(sizeof(struct list_t));

    list->size = 0;
    list->head = NULL;

    return list;
}

int free_it_all(struct node_t * node)
{
    if (node == NULL || node->next == NULL) {
        free(node);
        return;
    } else {
        free_it_all(node->next);
    }
    return;
}

int list_deinit(struct list_t * list)
{
    struct node_t * p;
    p = list->head;

    free_it_all(p); 

free_list:
    free(list);
    return 0;
}

int list_size(struct list_t *list)
{
    return list->size;
}

int list_is_empty(struct list_t *list)
{
    int rc = 0;

    if (list->size == 0)
        rc = 1;

    return rc;
}

int list_insert(struct list_t *list, char *key, int value)
{
    struct node_t * p;
    int rc = 0;

    p = malloc(sizeof(struct node_t));

    strncpy(p->k, key, sizeof(p->k));
    p->v = value;
    p->next = list->head;
    list->size++;

    list->head = p;

    return rc;
}

int list_lookup(struct list_t *list, char *key, int *value)
{
    struct node_t * p = list->head;
    int rc = 0;

    while (p) {
        if (strncmp(p->k, key, sizeof(p->k)) == 0) {
            *value = p->v;
            rc = 1;
            goto end;
        }
        p = p->next;
    }
end:
    return rc;
}

int list_remove(struct list_t *list, char *key)
{
    struct node_t * p = list->head;
    int rc = 0;

    // list->head->key matches. special case.
    if (strncmp(p->k, key, sizeof(p->k)) == 0) {
        list->head->next = list->head->next->next;
        free(p);    
        list->size--;
        rc = 1;
        goto end;
    }

    while (p->next)
    {
        if (strncmp(p->next->k, key, sizeof(p->k)) == 0) {
            p->next = p->next->next;
            free(p); 
            list->size--;
            rc = 1;
            goto end;
        }  
    }
end:
    return rc;
}

int list_contain(struct list_t *list, char *key, int *found)
{
    struct node_t * p = list->head;
    *found = 0;
    int rc = 0;
    while (p)
    {
        if (strncmp(p->k, key, sizeof(p->k)) == 0) {
            *found = 1;
            return rc;
        }
        p = p->next;
    }
    return rc;
}
