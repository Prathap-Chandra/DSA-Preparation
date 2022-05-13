/*
    Diameter of binary tree is nothing but
    maximumHeightOfLeftSubTree + maximumSumOfRightTree
*/

#include<iostream>
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

// Function to find the diameter of the binary tree. Note that the function
// returns the height of the subtree rooted at a given node, and the diameter
// is updated within the function as it is passed by reference
int getDiameter(struct node *node, int &diameter)
{
    // base case: tree is empty
    if (node == NULL) {
        return 0;
    }
 
    // get heights of left and right subtrees
    int left_height = getDiameter(node->left, diameter);
    int right_height = getDiameter(node->right, diameter);
 
    // calculate diameter "through" the current node
    int max_diameter = left_height + right_height + 1;
 
    // update maximum diameter (note that diameter "excluding" the current
    // node in the subtree rooted at the current node is already updated
    // since we are doing postorder traversal)
    diameter = max(diameter, max_diameter);
 
    // it is important to return the height of the subtree rooted at the current node
    return max(left_height, right_height) + 1;
}
 
int getDiameter(struct node *node)
{
    int diameter = 0;
    getDiameter(node, diameter);
 
    return diameter;
}

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
    // root->left->left->left = newNode(6);
    // root->left->left->left->left = newNode(4);

    cout << "\nInOrder Traversal: " << endl;
    traverseInOrder(root);

    cout << "\nDiameter of the tree: " << getDiameter(root) << endl;
}