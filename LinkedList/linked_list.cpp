/*
    Basic implementation of linkedlist
*/


#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *newNode(int data){
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
};

void insertIntoList(struct node *head, int data) {
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode(data);
}

// Print elements in the forward direction
void printListForward(struct node *head) {
    if (head->next != NULL)
    {
        cout << head->data << " ";
        printListForward(head->next);
    } else {
        cout << head->data << " ";
    }
}

// Print elements in the backward direction
void printListBackward(struct node *head) {
    if (head->next != NULL)
    {
        printListBackward(head->next);
        cout << head->data << " ";
    } else {
        cout << head->data << " ";
    }
}

int main() {
    struct node *head = newNode(1);
    for (int i = 2; i <= 10; i++) {
        insertIntoList(head, i);
    }

    cout << "\nElements in the linked list in forward: " << endl;
    printListForward(head);

    cout << "\nElements in the linked list in backward: " << endl;
    printListBackward(head);
}
