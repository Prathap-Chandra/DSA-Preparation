/*
    Lets explore different tree traversal methods
    1. Depth First Search
        1. InOrder Traversal
        2. InOrder Traversal
        3. InOrder Traversal
    2. Breadth First Search 
*/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void InOrderTraversal(struct node *node) {
    if (node != NULL) {
        InOrderTraversal(node->left);
        cout << node->data << " ";
        InOrderTraversal(node->right);
    }
}

void ReverseLevelOrderTraversal(struct node *node) {
}

int main() {
    struct node *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(18);
    root->right->right = newNode(22);

    cout << "\n InOrder Traversal: " << endl;
    InOrderTraversal(root);

    cout << "\n LevelOrder Traversal: " << endl;
    ReverseLevelOrderTraversal(root);
}