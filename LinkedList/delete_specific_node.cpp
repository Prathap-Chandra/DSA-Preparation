/*
    Delete Nth node from the linked list
    Time Complexity: 
    Space Complexity: 
*/

#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
};

void insertIntoList(struct node *head, int data) {
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = newNode(data);
}

void printList(struct node *head) {
    if(head->next != NULL) {
        cout << head->data << " ";
        printList(head->next);
    } else {
        cout << head->data << " ";
    }
}

void deleteSpecificNode(struct node *head, int nodeToBeDeleted) {
    struct node *current = head;
    struct node *previous = head;
    while (current->next != NULL)
    {
        if (current->data == nodeToBeDeleted) {
            previous->next = current->next;
            free(current);
            head = current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Node not found in the list." << endl; 
};

int main() {
    struct node *head = newNode(1);
    for (int i = 2; i <= 10; i++) {
        insertIntoList(head, i);
    }

    cout << "Elements in the linked list: " << endl;
    printList(head);

    cout << "Delete specific node from the list: " << endl;
    deleteSpecificNode(head, 10);

    cout << "Elements in the linked list: " << endl;
    printList(head);
}