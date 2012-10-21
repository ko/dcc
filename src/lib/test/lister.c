#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../log.h"
#include "../list.h"

int test1()
{
    int result;
    struct list_t * list;
    list = list_init();

    result = list_is_empty(list);
    if (result)
        log("success");
    else
        log("failed");

    list_deinit(list);

    return 0;
}

int test2()
{
    int result;
    int v;
    struct list_t * list;
    list = list_init();


    list_insert(list, "hello", 3);
    list_lookup(list, "hello", &v);

    if (v == 3)
        log("success");
    else
        log("failed");

    list_deinit(list);

    return 0;
}

int test3()
{
    int result;
    struct list_t * list;
    list = list_init();

    result = list_size(list);
    if (result)
        log("failed");
    else
        log("success");

    list_deinit(list);

    return 0;
}

int test4()
{
    int result;
    struct list_t * list;
    list = list_init();

    list_insert(list, "a", 1);
    if (list_size(list) != 1)
        log("failed");

    list_insert(list, "b", 2);
    if (list_size(list) != 2)
        log("failed");

    list_insert(list, "c", 3);
    if (list_size(list) != 3)
        log("failed");

    list_lookup(list, "b", &result);
    if (result == 2) 
        log("success");
    else
        log("failed");

    list_deinit(list);
    return 0;
}

int test5()
{
    int result;
    struct list_t * list;
    list = list_init();

    list_insert(list, "a", 1);
    if (list_size(list) != 1)
        log("failed");

    list_insert(list, "b", 2);
    if (list_size(list) != 2)
        log("failed");

    list_insert(list, "c", 3);
    if (list_size(list) != 3)
        log("failed");

    list_lookup(list, "b", &result);
    if (result != 2) 
        log("failed");

    result = list_remove(list, "b");
    if (result != 0)
        log("failed");

    list_contain(list, "b", &result);
    if (result)
        log("failed");

    list_contain(list, "c", &result);
    if (result == 1)
        log("success");
    else
        log("failed");

    list_deinit(list);
    return 0;
}

int test6() 
{
    int result;
    int rc;
    struct list_t * list;
    list = list_init();

    list_insert(list, "a", 1);
    list_insert(list, "b", 2);
    list_remove(list, "b");

    if (list_size(list) != 1) {
        log("failure");
        goto end;
    }

    rc = list_lookup(list, "b", &result);
    if (rc == -1 && result == -1)
        log("success");
    else
        log("failure, %d", rc);

end:
    list_deinit(list);
    return 0;
}

int main(void) 
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return;
}
