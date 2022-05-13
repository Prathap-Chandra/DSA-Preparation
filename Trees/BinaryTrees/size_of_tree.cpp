/*
    Calculate the size of the binary tree
    Time Complexity: O(n)
    Space Complexity: O(1)
*/ 

#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Creation of new node
struct node *newNode(int data) {
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

// InOrder Traversal
void traverseInOrder(struct node *node){
    if (node != NULL) {
        traverseInOrder(node->left);
        cout << node->data << " "; 
        traverseInOrder(node->right);
    }
};

// Size of the tree
int sizeOfTree(struct node *node){
    if (node != NULL && node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return sizeOfTree(node->left) + sizeOfTree(node->right) + 1;
    }
};

int main() {
    struct node *root = newNode(8);
    root->left = newNode(10);
    root->right = newNode(12);
    root->left->left = newNode(14);
    root->left->right = newNode(16);
    root->right->left = newNode(18);
    root->right->right = newNode(20);

    cout << "\nInOrder Traversal: " << endl;
    traverseInOrder(root);

    cout << "\nHeight of the tree: " << heightOfTree(root) << endl;

    cout << "\nSize Of Trees: " << sizeOfTree(root) << endl;
};






