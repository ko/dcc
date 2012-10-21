#include <assert.h>

#include "map.h"


/**
 * Initialize a map data structure.
 *
 * @return pointer to a map ADT
 */
map_t * map_init(void)
{
    map_t * map;

    map = (map_t *)list_init();
    assert(map);

    return map;
}

/**
 * Close up shop for our map ADT.
 *
 * @param map   map object
 */
void map_deinit(map_t * map)
{
    return list_deinit(map);
}

/**
 * Return the size (element count) of the map ADT.
 *
 * @param map   map object
 *
 * @return element count in the map
 */
int map_size(map_t * map)
{
    return list_size(map);
}

/**
 * Find if the map is empty (zero elements) or not.
 *
 * @param map   map object
 *
 * @return 1 if list is empty, 0 if list is not empty
 */
int map_is_empty(map_t * map)
{
    return list_is_empty(map);
}

/**
 * Insert a (key,value) tuple to the map ADT.
 *
 * @param map   map object
 * @param key   node's key
 * @param value node's value
 */
void map_put(map_t * map, char * key, int value)
{
    list_insert(map, key, value);
    return;
}

/**
 * Retrieve the value from the node where the given key
 * matches with a (key,value) tuple from the map ADT.
 *
 * @param map   map object
 * @param key   key for the value we want
 * @param value value associated with the key
 * 
 * @return 0 if key is found, -1 if key not found
 */
int map_get(map_t * map, char * key, int * value)
{
    list_lookup(map, key, value);
    return;
}

/**
 * Remove the node with a matching key from the map ADT.
 *
 * @param map   map object
 * @param key   key to search for and remove
 *
 * @return 0 if found and removed; -1 if element not found
 */
int map_remove(map_t * map, char * key)
{
    list_remove(map, key);
    return;
}
