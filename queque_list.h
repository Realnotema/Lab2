#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
#include "passengers.h"

typedef struct Item {
        passengers persone;
        struct Item *next;
} Item;

typedef struct queque {
        Item *head;
        Item *last;
        int count;
} queque;

void *identificare(int n);
int push(queque *arr, passengers add);
passengers pop(queque *arr);
int clean(queque *arr);
int cmp(queque *arr);
int first_raw(queque *arr);

#endif
