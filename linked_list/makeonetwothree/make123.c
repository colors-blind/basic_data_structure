#include <stdio.h>
#include <stdlib.h>

// 101
// make one->two->three linked list

struct node {
    int data;
    struct node* next;
};

struct node* buildonetwothree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    // return the head of linked list.
    return head;
}

// print out the list and return length of list
int print_out(struct node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct node* current = head;
    while (current) {
        count++;
        fprintf(stderr, "%d index data is %d, point is at %p, next at %p.\n", 
            count,
            current->data,
            current,
            current->next);
        current = current->next;   
    }
    return count;
}


int main() {
    struct node* head = buildonetwothree(); 
    int length = print_out(head);
    fprintf(stderr, "the length of list is %d\n", length);
    return 0;
}
