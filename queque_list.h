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

#endif
