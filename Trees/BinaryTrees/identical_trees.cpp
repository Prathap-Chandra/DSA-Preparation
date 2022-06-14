/*
    Given two tree. Check if they're identical or not.
    Two tree are identical if they've same data and arrangement of data is also same.
    Ex:    Tree1                Tree2   
                1                      1
            2      3               2     3
          4   5       6          4   5     7
    The above tree are not identical as leaf nodes are not matching
    Time Complexity: 
    Space Complexity:
*/ 

#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node *node = (struct node *) malloc (sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void traverseInOrder(struct node *node) {
    if (node != NULL) {
        traverseInOrder(node->left);
        cout << node->data << " ";
        traverseInOrder(node->right);
    }
};

bool areTreeIdentical(struct node *node1, struct node *node2) {
    if (node1 == NULL && node2 == NULL) {
        return true;
    }

    if (node1 != NULL && node2 != NULL) {
        return (
            node1->data == node2->data && 
            areTreeIdentical(node1->left, node2->left) && 
            areTreeIdentical(node1->right, node2->right)
        );
    }

    return false; 
};

int main() {
    struct node *root1 = newNode(14);
    root1->left = newNode(10);
    root1->right = newNode(20);
    root1->left->left = newNode(8);
    root1->left->right = newNode(12);
    root1->right->left = newNode(18);
    root1->right->right = newNode(22);

    cout << "\nInOrder Traversal of first tree: " << endl;
    traverseInOrder(root1);

    struct node *root2 = newNode(14);
    root2->left = newNode(10);
    root2->right = newNode(20);
    root2->left->left = newNode(8);
    root2->left->right = newNode(12);
    root2->right->left = newNode(18);
    root2->right->right = newNode(22);

    cout << "\nInOrder Traversal of second tree: " << endl;
    traverseInOrder(root2);

    cout << "\nTree1 & Tree2 are identical: " << std::boolalpha << areTreeIdentical(root1, root2) << endl;
};