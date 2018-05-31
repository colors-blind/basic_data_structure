#include <stdio.h>
#include <stdlib.h>

// make a list with for loop
// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

struct node {
    int data;
    struct node* next;
};

// add a head pointer, data hold the length of the list
struct node* make_list_with_for(int length) {
    struct node* head = NULL;
    head = malloc(sizeof(struct node));
    if (head == NULL) {
       fprintf(stderr, "malloc failed!");
       exit(1);
    }
    head->data = 0;
    head->next = NULL;
    struct node* record = head;
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

        head->next = new_node;
        head = new_node;

        record->data++;
    }
    return record;

}

void print_out(struct node* head) {
    struct node* current = head;
    while (current) {
        fprintf(stderr, "data -> %d, at->%p , next at->%p \n", current->data, current,
            current->next);
        current = current->next;
    }
}

struct node* insert_into_head(struct node* head, int value) {
    struct node* new_node = NULL;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
       fprintf(stderr, "malloc failed!");
       exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }
    // insert into head
    new_node->next = head->next;
    head->next = new_node;

    head->data++;
    return head;
}   

int main() {

    struct node* head = make_list_with_for(10);
    print_out(head);
    printf("\n");
    head = insert_into_head(head, 10);
    print_out(head);

    return 0;
}
