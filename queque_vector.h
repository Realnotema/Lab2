#ifndef QUEUE_VECTOR_H
#define QUEUE_VECTOR_H
#include "passengers.h"

typedef struct queque { 
        passengers *persone;
        int count;
        int top;
} queque;  

int push(queque *arr, passengers temp);
void *identificare(int n);
int clean(queque *arr);
passengers pop(queque *arr);
int cmp(queque *arr);
int first_raw(queque *arr);

#endif
