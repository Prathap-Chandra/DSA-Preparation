#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void traverseInOrder(struct node *temp){
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << temp->data << " ";
        traverseInOrder(temp->right);
    }
}

int main () {
    struct node *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(18);
    root->right->right = newNode(22);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(6);
    traverseInOrder(root);
    return 1;
}