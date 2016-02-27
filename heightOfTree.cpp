#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// Data structure for tree node.
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

// Insert an element in the tree.
Node* insert_tree( Node* root, int data )
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if ( root == NULL )
	{
		root= new Node;
		root->data = data;
		root->left = NULL:
		root->right = NULL;
	}
	else
	{
		if ( data < root->data )
			root->left = insert_tree( root->left, data );
		else
			root->right = insert_tree( root->right, data );
	}
	return root;
}

int height_tree( Node* root )
{
	if ( root == NULL )
		return 0;

	return 1 + max( height_tree( root->left ), height_tree( root->right ) );
}