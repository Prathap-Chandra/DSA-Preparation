#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// New node creation
struct node *newNode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void insert(struct node *root, struct node *node)
{
	if (node->data < root->data)
	{
		if (root->left)
		{
			insert(root->left, node);
		}
		else
		{
			root->left = node;
			return;
		}
	}
	else
	{
		if (root->right)
		{
			insert(root->right, node);
		}
		else
		{
			root->right = node;
			return;
		}
	}
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
	if (temp != NULL)
	{
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}

// Traverse Preorder
void traversePreOrder(struct node *temp)
{
	if (temp != NULL)
	{
		traversePreOrder(temp->left);
		cout << " " << temp->data;
		traversePreOrder(temp->right);
	}
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
	if (temp != NULL)
	{
		traversePostOrder(temp->left);
		cout << " " << temp->data;
		traversePostOrder(temp->right);
	}
}

struct node *findANode(struct node *root, int target)
{
	if (root == NULL)
	{
		cout << "Node not present: " << target;
		return root;
	}
	else if (target == root->data)
	{
		cout << "Node found: " << target;
		return root;
	}
	else if (target < root->data)
	{
		findANode(root->left, target);
	}
	else if (target > root->data)
	{
		findANode(root->right, target);
	}
}

void findMinNode(struct node *root)
{
	if (root->left)
	{
		findMinNode(root->left);
	}
	else
	{
		cout << "Min Node: " << root->data;
	}
}

void findMaxNode(struct node *root)
{
	if (root->right)
	{
		findMaxNode(root->right);
	}
	else
	{
		cout << "Max Node: " << root->data;
	}
}

struct node *InOrderSuccessor(struct node *root)
{
	if (root->left)
	{
		InOrderSuccessor(root->left);
	}
	else if (root->right)
	{
		InOrderSuccessor(root->right);
	}
	else if (root->left == NULL && root->right == NULL)
	{
		cout << "\nInOrderSuccessor Node: " << root->data;
		return root;
	}
}

struct node *InOrderPredecessor(struct node *root)
{
	if (root->right)
	{
		InOrderPredecessor(root->right);
	}
	else if (root->left)
	{
		InOrderPredecessor(root->left);
	}
	else if (root->left == NULL && root->right == NULL)
	{
		cout << "\nInOrderPredecessor Node: " << root->data;
		return root;
	}
}

void deleteNode(struct node *root, struct node *parent, int target)
{
	if (target < root->data)
	{
		parent = root;
		deleteNode(root->left, parent, target);
	}
	else if (target > root->data)
	{
		parent = root;
		deleteNode(root->right, parent, target);
	}
	else if (target == root->data)
	{
		cout << "Parent node: " << parent->data << endl;
		cout << "Parent left node: " << parent->left->data << endl;
		cout << "Parent right node: " << parent->right->data << endl;
		cout << "Child node: " << root->data << endl;
		if (root->left == NULL && root->right == NULL)
		{
			cout << "Leaf Node" << endl;
			InOrderPredecessor(root->left);
			InOrderSuccessor(root->right);
		}
		else if (root->left != NULL && root->right != NULL)
		{
			cout << "Node with 2 children" << endl;
			InOrderPredecessor(root->left);
			InOrderSuccessor(root->right);
		}
		else if (root->left != NULL || root->right != NULL)
		{
			cout << "Node with 1 children" << endl;
			InOrderPredecessor(root->left);
			InOrderSuccessor(root->right);
		}
	}
}

struct node *isTreeABST()
{
}

int main()
{
	struct node *root = newNode(18);
	int array[12] = {64, 2, 12, 16, 8, 4, 6, 10, 14, 20, 22, 24};
	int arraySize = sizeof(array) / sizeof(int);

	for (int i = 0; i < arraySize; i++)
	{
		struct node *myNode = newNode(array[i]);
		insert(root, myNode);
	}

	// cout << "\nPreorder traversal: " << endl;
	// traversePreOrder(root);

	cout << "\nInorder traversal: " << endl;
	traverseInOrder(root);

	// cout << "\nPostorder traversal: " << endl;
	// traversePostOrder(root);

	// cout << "\nFind a Node: " << endl;
	// findANode(root, 10);

	// cout << "\nFind Min Node: " << endl;
	// findMinNode(root);

	// cout << "\nFind Max Node: " << endl;
	// findMaxNode(root);

	cout << "\nDelete Node: " << endl;
	struct node *parent = newNode(0);
	deleteNode(root, parent, 8);

	cout << "\nInorder traversal: " << endl;
	traverseInOrder(root);
}