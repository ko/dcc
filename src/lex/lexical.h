#ifndef __LEXICAL_H__

#include <stdint.h>

#include "keywords.h"
#include "trigraphs.h"
#include "operators.h"

typedef struct token_s {
    uint32_t    type;
    union {
        char String[256];
        int Int;
        double Double;
    } value;
} token_t;

#define __LEXICAL_H__
#endif
