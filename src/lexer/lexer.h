//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_LEXER_H
#define C_EXPRESSION_PARSER_LEXER_H


#include "../util/linked_list.h"
#include "../util/string_util.h"
#include <string.h>


List *lexer(char *input) {
    List *number = list_init();
    List *tokens = list_init();
    char *signs = "+-*/()";

    for (int i = 0; i < strlen(input); i++) {
        if (!str_contains_char(input[i], signs)) {
            list_add(number, &input[i]);
        } else {
            list_add(tokens, list_to_str(number));
            list_add(tokens, &input[i]);

            // TODO: Free list
            number = list_init();
        }
    }

    return tokens;
}

#endif //C_EXPRESSION_PARSER_LEXER_H
