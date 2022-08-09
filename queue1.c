#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*)); // allocate memory for new node
    temp->data = x; // assign data to new node
    temp->next = NULL; // assign next to NULL
    if (front == NULL && rear == NULL) { // if queue is empty
        front = temp; // assign front to new node
        rear = temp; // assign rear to new node
    } else {
        rear->next = temp; // assign next of rear to new node
        rear = temp; // assign rear to new node
    }
}

void Dequeue() {
    struct Node* temp = front; // assign temp to front
    if (front == NULL) {
        return; // if queue is empty, return
    }
    if (front == rear) { // if queue has only one node
        front = NULL; // assign front to NULL
        rear = NULL; // assign rear to NULL
    } else {
        front = front->next; // assign front to next of front
    }
    free(temp); // free memory of temp
}