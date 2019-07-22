//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_BIN_OP_H
#define C_EXPRESSION_PARSER_BIN_OP_H

#include "operation.h"
#include <stdlib.h>

typedef struct BinOp {
    void *left;
    void *right;
    Operation op;
} BinOp;

BinOp *binop_init(void *left, void *right, Operation op) {
    BinOp *binop = malloc(sizeof(BinOp));
    binop->left = left;
    binop->right = right;
    binop->op = op;

    return binop;
}

#endif //C_EXPRESSION_PARSER_BIN_OP_H
