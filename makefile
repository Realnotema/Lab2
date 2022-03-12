all: comp_list

comp_list: main.c queque_list.c input.c
        gcc main.c queque_list.c input.c -o lab2.o -DLIST -lreadline -std=c11

comp_vector: main.c queque_vector.c input.c
        gcc main.c queque_vector.c input.c -o lab2.o -lreadline -std=c11

run_list: comp_list
        ./lab2.o

run_vector: comp_vector
        ./lab2.o

val: lab2.o
        valgrind --leak-check=full ./lab2.o
