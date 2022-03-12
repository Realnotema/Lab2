#include <stdio.h>
#include "queque_vector.h"
#include <stdlib.h>
#include <string.h>

typedef struct queque {
        passengers *persone;
        int count;
        int top;
} queque;

void *identificare(int n) {
        queque *arr = (queque *) malloc(sizeof(queque));
        arr->persone = (passengers *) calloc(n, sizeof(passengers));
        arr->count = n;
        arr->top = 0;
        return arr;
}

int push(queque *arr, passengers temp) {
        arr->top++;
        arr->persone[arr->top - 1].id = (char *) calloc(strlen(temp.id) + 1, sizeof(char));
        memmove(arr->persone[arr->top - 1].id, temp.id, strlen(temp.id));
        arr->persone[arr->top - 1].ta = temp.ta;
        arr->persone[arr->top - 1].ts = temp.ts;
        if (arr->top == arr->count) arr->top = 0;
        return 0;
}

int clean(queque *arr) {
        //for (int i = 0; i < arr->count; i++) free(arr->persone[i].id);
        free(arr->persone);
        arr->count = 0;
        arr->persone = NULL;
        return 0;
}

passengers pop(queque *arr) {
        passengers temp = arr->persone[arr->top];
        arr->top++;
        return temp;
}

int cmp(queque *arr) {
        if (arr->top != arr->count && arr->top + 1 != arr->count) {
                if (arr->persone[arr->top].ta == arr->persone[arr->top + 1].ta) {
                        return 1;
                } else return 0;
        } else return 0;
}

int first_raw(queque *arr) {
        int count = 1;
        int n = arr->persone[0].ta;
        printf("0\t%d\t", n);
        for (int i = 0; i < arr->count; i++) {
                if (arr->persone[i].ta != n) {
                        printf("%d\t", arr->persone[i].ta);
                        n = arr->persone[i].ta;
                        count++;
                }
        }
        printf("\n");
        return count;
}
