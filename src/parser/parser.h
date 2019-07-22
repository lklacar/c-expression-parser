//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_PARSER_H
#define C_EXPRESSION_PARSER_PARSER_H

#include "../util/linked_list.h"
#include "../lexer/token.h"
#include "bin_op.h"
#include <stdio.h>
#include <stdlib.h>


char operation(List *tokens, TokenType sign) {
    for(int i =0;i<tokens->size;i++){
        Token *token = list_get(tokens, i);
        if(token->type == sign) {
            BinOp *bin_op = binop_init(list_get(tokens, i-1), list_get(tokens, i-1), sign);
            
        }
    }
}

void parser(List *tokens) {
    int open = 0;
    int closed = 0;
    int open_index = -1;
    int closed_index = -1;

    for (int i = 0; i < tokens->size; i++) {
        Token *token = list_get(tokens, i);

        if (token->type == OPEN_BRACE) {
            open++;
            open_index = i;
        } else if (token->type == CLOSED_BRACE) {
            closed++;
            closed_index = i;
        }

        if (open == closed && open_index != -1 && closed_index != -1) {
            ListNode *start = list_get_node(tokens, open_index + 1);
            ListNode *end = list_get_node(tokens, closed_index);

            List *slice = list_init();
            for (int j = open_index + 1; j < closed_index; j++) {
                list_add(slice, list_get(tokens, j));
            }
            parser(slice);

            start->next = end;
            //TODO: Free nodes
            list_insert(tokens, list_get(slice, 0), open_index);
        }
    }

    char *signs = "*/+-";

    for(int i = 0;i<strlen(signs);i++){
        char res = operation(tokens, signs[i]);
    }


}


#endif //C_EXPRESSION_PARSER_PARSER_H
