#include "../map.h"
#include "../logger.h"

// Put -> Remove 
int test_1(struct map_t *m)
{
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
    return 2;
}

// Put -> Get -> Remove
int test_2(struct map_t *m)
{
    int v = 0;
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
    return 2;
}

int main(void) 
{
    struct map_t m = map_init();
    test_1(m);
    test_2(m);
    log("fin");
}
