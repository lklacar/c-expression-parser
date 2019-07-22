#include <stdio.h>
#include "util/linked_list.h"
#include "lexer/lexer.h"

int main() {

    List *tokens = lexer("1+2+3");


    for (int i = 0; i < tokens->size; i++) {
        void *val = list_get(tokens, i);

        printf("%s", (char *) val);
//        printf("%s", (char*)list_get(tokens, i));
    }

    return 0;
}