//
// Created by luka on 22.7.19..
//

#ifndef C_EXPRESSION_PARSER_LINKED_LIST_H
#define C_EXPRESSION_PARSER_LINKED_LIST_H

#include <stdlib.h>

typedef struct ListNode {
    void *value;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode *head;
    ListNode *tail;
    size_t size;
} List;

ListNode *node_init(void *value) {
    ListNode *node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

List *list_init() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_insert(List *list, void *value, int index) {
    ListNode *node = node_init(value);
    list->size = list->size + 1;
    if (list->size == 1) {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}

void *list_get(List *list, int index) {
    ListNode *current = list->head;

    int i = 0;
    while (current != NULL) {
        if (i == index) {
            return current->value;
        }
        i++;
        current = current->next;
    }

    return NULL;
}

void list_add(List *list, void *value) {
    list_insert(list, value, list->size);
}

char *list_to_str(List *list) {
    // TODO: Rewrite this
    char *str = malloc(list->size * sizeof(char));
    for (int i = 0; i < list->size; i++) {
        char *cp = list_get(list, i);
        char c = cp[0];
        str[i] = c;
    }

    return str;
}

#endif //C_EXPRESSION_PARSER_LINKED_LIST_H
