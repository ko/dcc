#ifndef __LEXICAL_H__

#include <stdint.h>

#include "keywords.h"
#include "trigraphs.h"
#include "operators.h"

struct token_t {
    uint32_t    type;
    union {
        char String[256];
        int Int;
        double Double;
    } value;
};

#define __LEXICAL_H__
#endif
