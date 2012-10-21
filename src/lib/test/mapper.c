#include "../map.h"
#include "../log.h"

/**
 * Put -> Remove 
 */
int test_1()
{
    map_t * m = map_init();

    map_put(m, "one", 1);
    if (map_size(m) != 1) {
        log("failed");
        return 1;
    }
    map_remove(m, "one");
    if (map_is_empty(m)) {
        log("success");
        return 0;
    } else {
        log("failed");
        return 1;
    }

    map_deinit(m);
    return 2;
}

/**
 * Put -> Get -> Remove
 */
int test_2()
{
    int v = 0;
    map_t * m = map_init();

    map_put(m, "two", 2);
    if (map_size(m) != 1) {
        log("failed");
        return 1;
    }
    map_get(m, "two", &v);
    if (v != 2) {
        log("failed");
        return 1;
    }
    map_remove(m, "two");
    if (map_is_empty(m)) {
        log("success");
        return 0;
    } else {
        log("failed");
        return 1;
    }

    map_deinit(m);
    return 2;
}

/**
 * Map_size for empty map
 */
int test_3()
{
    map_t * m = map_init();

    if (map_size(m) != 0)
        log("failed");
    else
        log("success");

    map_deinit(m);
    return 0;
}
int main(void) 
{
    test_1();
    test_2();
    test_3();
    log("fin");
}
