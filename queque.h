#ifndef QUEUE_H
#define QUEUE_H
#include "passengers.h"

int push(queque *arr, passengers temp);
void *identificare(int n);
int clean(queque *arr);
passengers pop(queque *arr);
int cmp(queque *arr);
int first_raw(queque *arr);

#endif
