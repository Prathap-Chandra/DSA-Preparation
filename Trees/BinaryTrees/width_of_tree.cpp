/*
    Problem: Width of the binry tree is defined as the no of nodes present in each level
    Ex:       8       -> level 1 -> width is 1
            4   10    -> level 2 -> width is 2
           2 5 9  12  -> level 3 -> width is 4
    Answer 4 (level 3 width 4 = 4 nodes)

    Time Complexity: 
    Space Complexity:
*/

#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

// Creation of new node
struct node *newNode(int data) {
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
};

int main () {
    struct node *root = newNode(14);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(18);
    root->right->right = newNode(22);
};