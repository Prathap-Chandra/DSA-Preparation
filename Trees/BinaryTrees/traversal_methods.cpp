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

void PreOrderTraversal(struct node *node) {
    if (node != NULL) {
        cout << node->data << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}

void InOrderTraversal(struct node *node) {
    if (node != NULL) {
        InOrderTraversal(node->left);
        cout << node->data << " ";
        InOrderTraversal(node->right);
    }
}

void PostOrderTraversal(struct node *node) {
    if (node != NULL) {
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout << node->data << " ";
    }
}

void LevelOrderTraversal(struct node *node) {
    if (node == NULL) return;
    queue<struct node *> Q;
    Q.push(node);
    while (!Q.empty())
    {
        struct node *current = Q.front();
        cout << current->data << " ";
        if(current->left) Q.push(current->left);
        if(current->right) Q.push(current->right);
        Q.pop();
    }
}

int main() {
    struct node *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(18);
    root->right->right = newNode(22);

    cout << "\n PreOrder Traversal: " << endl;
    PreOrderTraversal(root);

    cout << "\n InOrder Traversal: " << endl;
    InOrderTraversal(root);

    cout << "\n PostOrder Traversal: " << endl;
    PostOrderTraversal(root);

    cout << "\n LevelOrder Traversal: " << endl;
    LevelOrderTraversal(root);
}