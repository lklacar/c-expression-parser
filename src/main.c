#include <stdio.h>
#include "util/linked_list.h"
#include "lexer/lexer.h"
#include "parser/parser.h"

int main() {
    List *tokens = lexer("1+2+3");

    for (int i = 0; i < tokens->size; i++) {
        Token *val = (Token *) list_get(tokens, i);
        printf("[%s]", val->value);
    }

    parser(tokens);

    return 0;
}