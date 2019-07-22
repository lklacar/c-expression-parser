//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_LEXER_H
#define C_EXPRESSION_PARSER_LEXER_H


#include "../util/linked_list.h"
#include "../util/string_util.h"
#include "token.h"
#include <string.h>


List *lexer(char *input) {
    List *number = list_init();
    List *tokens = list_init();
    char *signs = "+-*/()";

    for (int i = 0; i < strlen(input); i++) {
        if (!str_contains_char(input[i], signs)) {
            list_add(number, &input[i]);
        } else {
            Token *number_token = token_init(list_to_str(number), TYPE_INTEGER);
            list_add(tokens, number_token);

            // TODO: Rewrite this
            TokenType token_type;
            if (input[i] == '+') {
                token_type = TYPE_PLUS;
            } else if (input[i] == '-') {
                token_type = TYPE_MINUS;
            } else if (input[i] == '*') {
                token_type = TYPE_STAR;
            } else if (input[i] == '/') {
                token_type = TYPE_SLASH;
            } else if (input[i] == '(') {
                token_type = TYPE_OPEN_BRACE;
            } else if (input[i] == ')') {
                token_type = TYPE_CLOSED_BRACE;
            } else {
                exit(1);
            }

            Token *operation_token = token_init(&input[i], token_type);
            list_add(tokens, operation_token);

            // TODO: Free list
            number = list_init();
        }
    }

    return tokens;
}

#endif //C_EXPRESSION_PARSER_LEXER_H
