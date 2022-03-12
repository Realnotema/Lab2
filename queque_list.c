#include <stdio.h>
#include "queque_list.h"
#include <stdlib.h>
#include <string.h>

void *identificare(int n) {
        queque *arr = (queque *) calloc(1, sizeof(queque));
        return arr;
}

int push(queque *arr, passengers add) {
        Item *temp = (Item *) malloc(sizeof(Item));
        temp->persone.id = (char *) calloc(strlen(add.id) + 1, sizeof(char));
        memmove(temp->persone.id, add.id, strlen(add.id));
        temp->persone.ta = add.ta;
        temp->persone.ts = add.ts;
        temp->next = NULL;
        arr->count++;
        if (arr->head == NULL) arr->head = temp;
        if (arr->last != NULL) {
                arr->last->next = temp;
        }
        arr->last = temp;
        return 0;
}

passengers pop(queque *arr) {
        if (arr->head == NULL) {
                exit(-1);
        }
        passengers temp = arr->head->persone;
        Item *tmp_head = arr->head;
        arr->head = arr->head->next;
        free(tmp_head);
        if (arr->head == NULL) {
                arr->last = NULL;
        }
        return temp;
}

int clean(queque *arr) {
        while (arr->head != NULL) {
                Item *tmp = arr->head;
                free(arr->head->persone.id);
                arr->head = arr->head->next;
                free(tmp);
        }
        return 0;
}

int cmp(queque *arr) {
        if (arr->head != arr->last) {
                if (arr->head->persone.ta == arr->head->next->persone.ta) {
                        return 1;
                } else return 0;
        } else return 0;
}

int first_raw(queque *arr) {
        int count = 1;
        int n = arr->head->persone.ta;
        queque *temp = (queque *) calloc(1, sizeof(queque));;
        printf("0\t%d\t", n);
        temp->head = arr->head->next;
        for (int i = 0; i < arr->count - 1; i++) {
                if (temp->head->persone.ta != n) {
                        printf("%d\t", temp->head->persone.ta);
                        n = temp->head->persone.ta;
                        count++;
                }
                temp->head = temp->head->next;
        }
        printf("\n");
        free(temp);
        return count;
}
