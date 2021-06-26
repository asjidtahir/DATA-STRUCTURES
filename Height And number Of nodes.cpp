#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
};


int height(node* node)
{
	/* base case tree is empty */
	if (node == NULL)
	{
		return 0;
	}

	else
	{
		int lDepth = height(node->left);
		int rDepth = height(node->right);

		if (lDepth > rDepth)
		{
			return(lDepth + 1);
		}

		else
		{
			return(rDepth + 1);
		}
	}


}
int isBalanced(node* root)
{
	int lh; /* for height of left subtree */
	int rh; /* for height of right subtree */
	int balance;

	/* If tree is empty then return true */
	if (root == NULL)
		return 1;

	/* Get the height of left and right sub trees */
	lh = height(root->left);
	rh = height(root->right);

	balance = lh - rh;
	return balance;

}


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	int z;
	z = isBalanced(root);
	cout << z << endl;
	if (isBalanced(root))

		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";
	return 0;
}
