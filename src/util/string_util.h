//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_STRING_UTIL_H
#define C_EXPRESSION_PARSER_STRING_UTIL_H

#include <string.h>

char str_contains_char(char c, char *array) {
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == c) {
            return 1;
        }
    }

    return 0;
}


#endif //C_EXPRESSION_PARSER_STRING_UTIL_H
