/*************************************
* Lab 1 Exercise 2
* Name:
* Student No:
* Lab Group:
*************************************/

#include "node.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add in your implementation below to the respective functions
// Feel free to add any headers you deem fit (although you do not need to)

// Inserts a new node with data value at index (counting from head
// starting at 0).
// Note: index is guaranteed to be valid.
void insert_node_at(list *lst, int index, int data) {
    
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;

    node *temp = lst->head;

    if (lst->head == NULL) {
        lst->head = newNode;
        newNode->next = newNode;
    } else if (temp != NULL) {
        for(int i = 1; i < index; i++) {
            temp = temp->next;
        }

        if (index == 0) {
            node *last = lst->head->next;
            while (last->next != lst->head) {
                last = last->next;
            }
            newNode->next = lst->head;
            lst->head = newNode;
            last->next = lst->head;
        } else {
            node *cur;
            cur = temp->next;
            temp->next = newNode;
            newNode->next = cur;
        }
    }

}

// Deletes node at index (counting from head starting from 0).
// Note: index is guarenteed to be valid.
void delete_node_at(list *lst, int index) {
    node *temp = lst->head;

    if (lst->head->next == lst->head) {
        lst->head = NULL;
    } else {
        for (int i = 1; i < index; i ++) {
            if (temp -> next != NULL) {
                temp = temp->next;
            }
        }
        if (index == 0) {
            while (temp->next != lst->head) {
                temp = temp->next;
            }
            temp->next = lst->head->next;
            lst->head = lst->head->next;

        } else {
            temp->next = temp->next->next; 
        }
    }


}

// Rotates list by the given offset.
// Note: offset is guarenteed to be non-negative.
void rotate_list(list *lst, int offset) {
    for (int i = 0; i < offset; i++) {
        lst->head = lst->head->next;
    }
}

// Reverses the list, with the original "tail" node
// becoming the new head node.
void reverse_list(list *lst) {
    if (lst->head != NULL) {
        node *last = lst->head;
        node *prev = lst->head;
        node *cur = lst->head->next;
        node *head = lst->head->next;
        while (head != last) {
            head = head->next;
            cur->next = prev;
            prev = cur;
            cur = head;
        }
        cur->next = prev;
        lst->head = prev;
    }
 
}

// Resets list to an empty state (no nodes) and frees
// any allocated memory in the process
void reset_list(list *lst) {
    // if (lst->head->next == lst->head) {
    //     free(lst->head);
    //     lst->head = NULL;
    // } 
    if (lst->head != NULL) {

        node *ptr = lst->head->next;
        while (ptr != lst->head) {
            node *temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
        free(lst->head);
        lst->head = NULL;
    }
}

