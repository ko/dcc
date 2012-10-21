#include "lexical.h"
#include "map.h"

void init_control_flow(map_t * map)
{
    map_put(map, "while",    R_WHILE);
    map_put(map, "if",       R_IF);
    map_put(map, "else",     R_ELSE);
    map_put(map, "for",      R_FOR);
    map_put(map, "goto",     R_GOTO);
    map_put(map, "continue", R_CONTINUE);

    map_put(map, "break",    R_BREAK);

    return;
}

void init_data_types(map_t * map)
{
    map_put(map, "char",     R_CHAR);
    map_put(map, "int",      R_INT);

    return;
}

void init_operators(map_t *map)
{
    map_put(map, "+",        O_PLUS);
    map_put(map, "=",        O_ASSIGN);

    return;
}

void init_lexical(map_t *map)
{
    init_control_flow(map);
    init_data_types(map);
    init_operators(map);
}
