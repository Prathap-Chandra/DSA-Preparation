/*
    find the height of a binary tree
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

// find the height of the tree
int heightOfTree(struct node *node) {
    if (node != NULL && node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        int heightOfLeftSubTree = heightOfTree(node->left);
        int heightOfRightSubTree = heightOfTree(node->right);
        if (heightOfLeftSubTree > heightOfRightSubTree) {
            return heightOfLeftSubTree + 1;
        } else {
            return heightOfRightSubTree + 1;
        }
    }
};

// InOrder Traversal
void traverseInOrder(struct node *node){
    if (node != NULL) {
        traverseInOrder(node->left);
        cout << node->data << " "; 
        traverseInOrder(node->right);
    }
};

int main() {
    struct node *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(18);
    root->right->right = newNode(22);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(6);

    cout << "\nInOrder Traversal: " << endl;
    traverseInOrder(root);
    
    cout << "\nHeight of the tree: " << heightOfTree(root) << endl;
};