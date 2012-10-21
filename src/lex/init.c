#include "lexical.h"
#include "map.h"

void init_control_flow(map_t * map)
{
    map_put(map, "while",    T_WHILE);
    map_put(map, "if",       T_IF);
    map_put(map, "else",     T_ELSE);
    map_put(map, "for",      T_FOR);
    map_put(map, "goto",     T_GOTO);
    map_put(map, "continue", T_CONTINUE);

    map_put(map, "break",    T_BREAK);

    return;
}

void init_data_types(map_t * map)
{
    map_put(map, "char",     T_CHAR);
    map_put(map, "int",      T_INT);

    return;
}

void init_operators(map_t *map)
{
    map_put(map, "+",        T_PLUS);
    map_put(map, "=",        T_ASSIGN);

    return;
}

void init_lexical(map_t *map)
{
    init_control_flow(map);
    init_data_types(map);
    init_operators(map);
}
