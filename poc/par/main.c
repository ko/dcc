#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

int print_help()
{
    int rc = 1;

    printf("this must be done\n");

    return rc;
}

int main(int argc, char **argv) 
{
    int fd;
    int rc = 0;

    switch (argc) {
    case 2:
        fd = open(argv[1], O_RDONLY);    
        assert(fd);
        break;
    default:
        rc = print_help();
        goto finish;
    }

cleanup:
    close(fd);

finish:
    exit(rc);
}
