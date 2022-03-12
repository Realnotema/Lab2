#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passengers.h"
#include "queque_list.h"
#include <readline/readline.h>

int get_int() {
        char *input = readline("");
        if (input == NULL) {
                free(input);
                return 0;
        }
        if (atoi(input) == 0){
                free(input);
                return 0;
        }
        int output = atoi(input);
        free(input);
        return output;
}

char *enter() {
        char *str = readline("=>  ");
        char *temp = str;
        int n = 0;
        while (*temp != '\0') {
                if (*temp == '/') {
                        n++;
                }
                temp++;
        }
        if (n != 2) {
                return NULL;
        }
        return str;
}

int input(queque *arr, char *input) {
        if (input == NULL) return 1;
        passengers temp;
        char *first, *last;
        first = strchr(input, '/');
        temp.id = (char *) calloc((first - input + 1), sizeof(char));
        memmove(temp.id, input, first - input);
        last = first;
        temp.ta = atoi(first + 1);
        if (temp.ta == 0) return 1;
        last = strchr(first + 1, '/');
        temp.ts = atoi(last + 1);
        if (temp.ts == 0) return 1;
        push(arr, temp);
        free(temp.id);
        return 0;
}

int clear_temp(passengers **final, int ilen, int jlen) {
        for (int i = 0; i < ilen; i++) {
                for (int j = 0; j < jlen; j++) {
                        if (final[i][j].id != NULL) free(final[i][j].id);
                }
                free(final[i]);
        }
        free(final);
        return 0;
}

passengers **create_array(queque *arr, int timer, int numbers) {
        passengers **final =  calloc(timer, sizeof(passengers *));
        for (int i = 0; i < timer; i++) final[i] = calloc(numbers, sizeof(passengers));
        int comparator = cmp(arr);
        final[0][0] = pop(arr); // pop
        for(int i = 0, j = 0, k = 1; i < numbers, j < timer; k++) {
                if (k != 1) comparator = cmp(arr);
                if (k >= arr->count) {
                        return final;
                } else {
                        if (comparator == 1) {
                                j++;
                                final[i][j] = pop(arr);//arr->persone[k]; // pop
                        } else {
                                if (j == numbers - 1) {
                                        j = 0;
                                } else j++;
                                i++;
                                final[i][j] = pop(arr);//arr->persone[k]; // pop
                        }
                }
        }
}

int output(queque *arr, int counters, int size) {
        int j = first_raw(arr);
        passengers **final = create_array(arr, j, counters);
        for (int k = 0; k < counters; k++) {
                printf("No%d\t", k + 1);
                for (int i = 0; i < j; i++) {
                         int z = 0;
                        printf("№%d ", k + 1);
                         do {
                                  if (final[z][k].id != NULL) printf("%s ", final[z][k].id);
                                  z++;
                        } while (z <= i);
                        printf("\t");
                }
                printf("\n");
        }
        clear_temp(final, j, counters);
        return 0;
}

int main() {
        int counters = 0;
        int count_pass = 0;
        char *str = NULL;
        do {
                printf("Enter count of check-in counters: ");
                counters = get_int();
        } while (counters == 0);
        do {
                printf("Enter count of passengers: ");
                count_pass = get_int();
        } while (count_pass == 0);
        queque *arr = identificare(count_pass);
        printf("Enter passengers:\n");
        for (int i = 0; i < count_pass; i++) {
                printf("The %d one ", i + 1);
                str = enter();
                if (str == NULL) {
                        printf("Error: Try again\n");
                        i--;
                        continue;
                }
                input(arr, str);
                free(str);
        }
        if (arr != NULL) output(arr, counters, count_pass);
        clean(arr);
        free(arr);
        return 0;
}
