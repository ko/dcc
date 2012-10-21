#include <stdio.h>
#include <string.h>

#include "lexical.h"
#include "map.h"
#include "init.h"

static int token_lookup(char * str, int *val);
static int token_scanner(FILE *fp, token_t * token);
static void print_help(void);

map_t * map;

static int token_lookup(char * str, int *val)
{
    return map_get(map, str, val);
}

static int token_scanner(FILE *fp, token_t * token)
{
    int i, c, cnext, toktype;
    int rc = 0;

    c = getc(fp);
    while (isspace(c))
        c = getc(fp);

    switch(c) {
    case '/':
        // we're at a comment or a division
        cnext = getc(fp);
        if (cnext == '*' || cnext == '/')
            ; // handle the comment
        else
            ungetc(cnext, fp);

    case '+':
        token->value.String[0] = '+';
        token->type = O_PLUS;
        break;

    case '=':
        token->value.String[0] = '=';
        token->type = O_ASSIGN;
        break;

    case ';':
        token->value.String[0] = ';';
        token->type = S_SEMICOLON;
        break;
    case EOF:
        token->type = R_END;
        return R_END;

    case '"':
        token->type = T_STRING;
        // TODO finish this implementation
        break;

    case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': case '0':
        // Assume integer
        token->type = T_INTEGER;
        token->value.Int = c - '0';
        while (isdigit(cnext = getc(fp))) 
            token->value.Int = token->value.Int * 10 + c - '0';

        // Possible double or float
        // Assume only double because floats are TBA
        if (cnext == '.') {
            token->type = T_DOUBLE;
            token->value.Double = token->value.Double;
            // TODO finish this implementation
        } else {
            ungetc(cnext, fp);
        }
        break;

    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
    case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
    case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
    case 's': case 't': case 'u': case 'v': case 'w': case 'x':
    case 'y': case 'z':
        token->value.String[0] = c; 
        for (i = 1; isalpha(cnext = getc(fp)); i++) 
            token->value.String[i] = cnext;
        rc = token_lookup(token->value.String, &toktype);
        if (rc == 0) 
            token->type = toktype;
        else 
            // not a reserved word. must be an identifier
            token->type = T_IDENTIFIER;
        break;
    default:
        token->value.Int = c;
        token->type = R_UNDEFINED;
    }

    return rc;
}

static void print_help(void) 
{
    printf("help info here\n");
    return;
}

int main(int argc, char **argv) 
{
    FILE * fp = NULL;
    token_t token = {0};
    map = map_init();
    init_lexical(map);

    switch(argc) {
    case 2:
        fp = fopen(argv[1], "r");
        break;
    default:
        print_help();
        goto exit;
    }

    while (token_scanner(fp, &token) != R_END) {
        if (token.type) {
            if (token.value.String)
                printf("%s %d\n", token.value.String, token.type);
            else if (token.value.Int)
                printf("%d %d\n", token.value.Int, token.type);
            memset(&token, 0, sizeof(token));
        }
    }

exit:
    return 0;
}
