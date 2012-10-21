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

/**
 * Helper function for the list_deinit().
 *
 * @param node  list element/node
 */
void free_it_all(struct node_t * node)
{
    if (node == NULL || node->next == NULL) {
        free(node);
        return;
    } else {
        free_it_all(node->next);
    }
    return;
}

/**
 * Close up shop for the list; free the memory.
 *
 * @param list  linked list header
 */
void list_deinit(void * list)
{
    struct list_t * l = (struct list_t *)list;
    struct node_t * p;
    p = l->head;

    free_it_all(p); 

free_list:
    free(list);
    return;
}

/**
 * Get the size of the linked list.
 *
 * @param list  linked list header
 *
 * @return size of the list as an int
 */
int list_size(void * list)
{
    struct list_t * l = (struct list_t *)list;
    return l->size;
}

int list_is_empty(void * list)
{
    struct list_t * l = (struct list_t *)list;
    int rc = 0;

    if (l->size == 0)
        rc = 1;

    return rc;
}

/**
 * Insert a node to the linked list.
 *
 * @param list  linked list header
 * @param key   node's key
 * @param value node's associated value
 *
 * @return 0 for success
 */
int list_insert(void * list, char *key, int value)
{
    struct list_t * l = (struct list_t *)list;
    struct node_t * p;
    int rc = 0;

    p = malloc(sizeof(struct node_t));

    strncpy(p->k, key, sizeof(p->k));
    p->v = value;
    p->next = l->head;
    l->size++;

    l->head = p;

    return rc;
}

/**
 * Looks up the target key and passes along its value 
 * through the function argument.
 *
 * @param list  linked list header
 * @param key   key that we want to find the value of
 * @param value value if the key exists; if not exist, set to -1
 *
 * @return 0 if key found, -1 if key not found
 */  
int list_lookup(void * list, char *key, int *value)
{
    struct list_t * l = (struct list_t *)list;
    struct node_t * p = l->head;
    int rc = -1;
    *value = -1;

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

/**
 * Remove a node from the linked list if found.
 *
 * @param list  linked list header
 * @param key   target key to match in the nodes
 *
 * @return 0 if found and removed; -1 if element not found
 */
int list_remove(void * list, char *key)
{
    struct list_t * l = (struct list_t *)list;
    struct node_t * p = l->head;
    int rc = -1;

    // list->head->key matches. special case.
    if (strncmp(p->k, key, sizeof(p->k)) == 0) {
        l->head = l->head->next;    // about to free p; use l here
        free(p);    
        l->size--;
        rc = 0;
        goto end;
    }

    while (p->next)
    {
        if (strncmp(p->next->k, key, sizeof(p->k)) == 0) {
            p->next = p->next->next;
            free(p); 
            l->size--;
            rc = 0;
            goto end;
        }  
    }
end:
    return rc;
}

/**
 * Whether an element exists in the linked list.
 *
 * @param list  linked list header
 * @param key   key being searched for
 * @param found 1 if found, 0 otherwise
 *
 * @return 0 on success for the function itself
 */
int list_contain(void * list, char *key, int *found)
{
    struct list_t * l = (struct list_t *)list;
    struct node_t * p = l->head;
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
