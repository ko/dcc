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

int main(void) 
{
    int rc;
    
    rc = test1();
    rc = test2();
    rc = test3();
}
