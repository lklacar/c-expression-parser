cmake_minimum_required(VERSION 3.14)
project(c_expression_parser C)

set(CMAKE_C_STANDARD 99)

add_executable(c_expression_parser src/main.c src/parser/bin_op.h src/parser/operation.h src/util/linked_list.h src/lexer/token.h src/lexer/lexer.h src/util/string_util.h src/parser/parser.h)