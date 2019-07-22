//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_TOKEN_H
#define C_EXPRESSION_PARSER_TOKEN_H

#include <stdlib.h>

typedef enum TokenType {
    TYPE_INTEGER,
    TYPE_OPEN_BRACE,
    TYPE_CLOSED_BRACE,
    TYPE_PLUS,
    TYPE_MINUS,
    TYPE_STAR,
    TYPE_SLASH
} TokenType;

typedef struct Token {
    TokenType type;
    char *value;
} Token;

Token *token_init(char *value, TokenType type) {
    Token *token = malloc(sizeof(Token));
    token->value = value;
    token->type = type;
    return token;
}

#endif //C_EXPRESSION_PARSER_TOKEN_H
