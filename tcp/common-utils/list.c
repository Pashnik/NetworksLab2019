#include "headers/list.h"

int eq(Client *cli1, Client *cli2) {
    return cli1->id == cli2->id;
}

void free_space(Node *node) {
    free(node->client);
    free(node);
}

void pop(List *list) {
    Node *prev = list->node;
    list->node = list->node->next;
    free_space(prev);
    list->size -= 1;
}

int exists(List *list, Client *client) {
    Node *current = list->node;
    while (current != NULL) {
        if (eq(current->client, client)) return 0;
    }
    return 1;
}

void push(List *list, Client *client) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->client = client;
    tmp->next = list->node;
    list->node = tmp;
    list->size += 1;
}

void delete(List *list, Client *client) {
    if (!exists(list, client)) raise_error(NO_SUCH_ELEMENT);
    if (list->size == 1 || eq(list->node->client, client)) return pop(list);
    Node *current = list->node->next;
    Node *prev = list->node;

    while (!eq(current->client, client)) {
        current = current->next;
        prev = prev->next;
    }
    prev->next = current->next;
    free_space(current);
    list->size -= 1;
}

