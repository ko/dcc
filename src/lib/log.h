#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>

#define log(str, args...) \
    printf("%s:%d:%s\n", __FUNCTION__, __LINE__, str, ## args)

#endif
