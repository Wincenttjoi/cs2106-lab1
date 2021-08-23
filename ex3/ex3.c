/*************************************
* Lab 1 Exercise 3
* Name:
* Student No:
* Lab Group:
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function_pointers.h"
#include "node.h"

// The runner is empty now! Modify it to fulfill the requirements of the
// exercise. You can use ex2.c as a template

// DO NOT initialize the func_list array in this file. All initialization
// logic for func_list should go into function_pointers.c.

// Macros
#define SUM_LIST 0
#define INSERT_AT 1
#define DELETE_AT 2
#define ROTATE_LIST 3
#define REVERSE_LIST 4
#define RESET_LIST 5
#define MAP 6

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Error: expecting 1 argument, %d found\n", argc - 1);
        exit(1);
    }

    // We read in the file name provided as argument
    char *fname = argv[1];

    // Update the array of function pointers
    // DO NOT REMOVE THIS CALL
    // (You may leave the function empty if you do not need it)
    update_functions();

    // Rest of code logic here

    FILE *f = fopen(fname, "r");

    if (f == NULL) {
        exit(1);
    }

    run_instruction(f);

    fclose(f);

}

// Takes an instruction enum and runs the corresponding function
// We assume input always has the right format (no input validation on runner)
void run_instruction(FILE *f) {
    int instr, arg, data, offset, func_index;
    list *lst = (list*) malloc(sizeof(list));
    lst->head = NULL;

    while (fscanf(f, "%d", &instr) == 1) {

        switch (instr) {
            case SUM_LIST:
                printf("%li\n", sum_list(lst));
                // print_list(lst);
                break;
            case INSERT_AT:
                fscanf(f, "%d %d", &arg, &data);
                insert_node_at(lst, arg, data);
                break;
            case DELETE_AT:
                fscanf(f, "%d", &arg);
                delete_node_at(lst, arg);
                break;
            case ROTATE_LIST:
                fscanf(f, "%d", &offset);
                rotate_list(lst, offset);
                break;
            case REVERSE_LIST:
                reverse_list(lst);
                break;
            case RESET_LIST:
                reset_list(lst);
                break;
            case MAP:
                fscanf(f, "%d", &func_index);
                map(lst, func_list[func_index]);
                break;
        }
    }

}
