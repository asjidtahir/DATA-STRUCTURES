#include<iostream>
using namespace std;
struct node {
    int value;
    node* left, * right;
};
class BST
{
private:
    node* temp;
    int key;
public:
    node* root;
    int value;
    BST();
    node* createNode(int);
    void options();
    void insertion(node*);
    void deletion(node*, int);
    void inOrder(node*);
};
BST::BST()
{
    root = temp = NULL;
    value = key = 0;
}
node* BST::createNode(int value)
{
    node* newNode = new node;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void BST::options() {
    cout << "/t OPTIONS/t" << endl;
    cout << "1-insertion()" << endl;
    cout << "2-deletion()" << endl;
    cout << "3-inOrder()" << endl;
}
void BST::insertion(node* temp)
{
    if (root == NULL)
    {
        temp = createNode(value);
        root = temp;
        return;
    }
    if (temp->value == value)
    {
        cout << "Duplicate found!!!" << endl;
        return;
    }
    if (value < temp->value)
    {
        if (temp->left == NULL)
        {
            temp->left = createNode(value);

        }
        else
        {
            insertion(temp->left);
        }
        return;
    }
    if (value > temp->value)
    {
        if (temp->right == NULL)
        {
            temp->right = createNode(value);

        }
        else
        {
            insertion(temp->right);
        }
        return;
    }
}
void BST::inOrder(node* temp)
{
    if (root == NULL)
    {
        cout << "tree is empty!!!" << endl;
        return;
    }
    if (temp->left != NULL)
        inOrder(temp->left);
    cout << temp->value << " ";
    if (temp->right != NULL)
        inOrder(temp->right);

    return;
}
void BST::deletion(node* leafNode, int key)
{
    leafNode = root;
    //if tree is empty
    if (leafNode == NULL)
    {
        return; // important to return
    }
    if (key < leafNode->value)
    {
        return deletion(leafNode->left, key); // important to return
    }
    if (key > leafNode->value)
    {
        return deletion(leafNode->right, key); // important to return
    }
    // if program flow reaches here, it means we found the leafNode we want to delete
    //case 1:node deletion, incase, left & right leaf nodes are NULL
    if (leafNode->right == NULL && leafNode->left == NULL)
    {
        delete leafNode;
        return; //important to return the flow
    }
    node* deleteNode = leafNode;
    //case 2:node having one child either left or right
    if (leafNode->left != NULL && leafNode->right == NULL)
    {
        leafNode = leafNode->left;
        delete deleteNode;
        return; //important to return the flow
    }
    if (leafNode->right != NULL && leafNode->left == NULL)
    {
        leafNode = leafNode->right;
        delete deleteNode;
        return; //important to return the flow
    }
    //case 3:node having 2 childs (simply move to right node, then traverse to the left most node from there and move it to leaf node location)
    node* currentRoot = leafNode;
    deleteNode = currentRoot->right;
    while (deleteNode->left != NULL)
    {
        currentRoot = deleteNode;
        deleteNode = deleteNode->left;
    }
    // replace the value of deleteNode with leafNode & then delete deleteNode
    leafNode->value = deleteNode->value;
    currentRoot->left = NULL;
    delete deleteNode;
}
int main()
{
    BST obj;
    int choice;
    int key;
    do {
        obj.options();
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter number to insert: ";
            cin >> obj.value;
            obj.insertion(obj.root);
        }
        else if (choice == 2)
        {
            cout << "Enter key: ";
            cin >> key;
            obj.deletion(obj.root, key);
        }
        else if (choice == 3)
        {
            obj.inOrder(obj.root);
        }
        else
        {
            exit(0);
        }
    } while (5);
    return 0;
}