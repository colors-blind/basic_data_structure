#include <stdio.h>
#include <stdlib.h>

// make a list with for loop
// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

struct node {
    int data;
    struct node* next;
};

// add a head pointer, data hold the length of the list
struct node* make_with_tail(int length) {
    struct node* head = NULL;
    head = malloc(sizeof(struct node));
    if (head == NULL) {
       fprintf(stderr, "malloc failed!");
       exit(1);
    }
    head->data = 0;
    head->next = NULL;
    struct node* tail = head;
    int i = 0;
    for (i = 0; i < length; i++) {
        struct node* new_node = NULL;
        new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            fprintf(stderr, "malloc failed!");
            exit(1);
        }
        new_node->data = i;
        new_node->next = NULL;
        // build with a tail pointer
        tail->next = new_node;
        tail = new_node;

        head->data++;
    }
    return head;

}

void print_out(struct node* head) {
    struct node* current = head;
    while (current) {
        fprintf(stderr, "data -> %d, at->%p , next at->%p \n", current->data, current,
            current->next);
        current = current->next;
    }
}


int main() {

    struct node* head = make_with_tail(10);
    print_out(head);

    return 0;
}
