#include "lexical.h"
#include "map.h"
#include "init.h"


int main(int argc, char **argv) 
{
    map_t * map = map_init();
    init_lexical(map);
}
