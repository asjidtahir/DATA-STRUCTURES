#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left, * right;
    node()
    {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }
    node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    node* root;

    BST()
    {
        root = nullptr;
    }
    bool isEmpty()
    {
        if (root == nullptr)
        {
            return true;
        }
        else
            return false;
    }
    node* insertNode(node* temp, node* new_node)
    {

        if (temp == nullptr)
        {
            cout << "Insertion Successful !!!\n";
            return new_node;
        }
        if (new_node->data < temp->data)
        {
            temp->left = insertNode(temp->left, new_node);
            cout << "NODE ADDED to the left\n";
        }
        else if (new_node->data > temp->data)
        {
            temp->right = insertNode(temp->right, new_node);
            cout << "NODE ADDED to the right\n";
        }
        else
            cout << "Duplicate Values Not Allowed!!!\n";
    }

    void insertNode(node* new_node)
    {

        if (root == nullptr)
        {
            root = new_node;
            cout << "Insertion Done\n";
        }
        else
        {
            node* temp = root;
            while (temp != nullptr)
            {
                if (new_node->data == temp->data)
                {
                    cout << "Value already Exits!!!\n";
                    return;
                }
                else if ((new_node->data > temp->data) && (temp->right == nullptr))
                {
                    temp->right = new_node;
                    cout << "NODE ADDED to the right\n";
                    break;
                }
                else if (new_node->data > temp->data)
                {
                    temp = temp->right;
                }
                else if ((new_node->data < temp->data) && (temp->left == nullptr))
                {
                    temp->left = new_node;
                    cout << "NODE ADDED to the left\n";
                    break;
                }
                else if (new_node->data < temp->data)
                {
                    temp = temp->left;
                }
            }
        }
    }

    node* delete_node(node* temp, int value)
    {
        if (temp == NULL)
        {
            cout << "TREE Emtpy!!!\n";
        }
        else
        {
            if (value > temp->data)
            {
                temp->right = delete_node(temp->right, value);
            }
            else if (value < temp->data)
            {
                temp->left = delete_node(temp->left, value);
            }
            else {
                //if node has no childs
                //Case '01'
                if (temp->left == NULL && temp->right == NULL)
                {
                    delete temp;
                    return temp->left;
                }
                //if node has one child only
                //Case '02'
                else if (temp->right == NULL && temp->left != NULL)
                {
                    node* deletenode = temp->left;
                    if (temp == root)
                        root = deletenode;
                    delete temp;
                    return deletenode;
                }
                else if (temp->right != NULL && temp->left == NULL)
                {
                    node* deletenode = temp->right;
                    if (temp == root)
                        root = deletenode;
                    delete temp;
                    return deletenode;
                }
                //if node has two child find smallest node of right sub tree
                //Case '03'
                else if (temp->left != NULL && temp->right != NULL)
                {

                    node* deletenode = mininode(temp->right);
                    temp->data = deletenode->data;
                    temp->right = delete_node(temp->right, temp->data);
                }
            } 
            return temp;
        }
    }
    void inOrder(node* new_node)
    {
        if (new_node == nullptr)
            return;
        inOrder(new_node->left);
        cout << new_node->data << " ";
        inOrder(new_node->right);
    }

    node* mininode(node* new_node)
    {
        if (new_node->left == NULL)
        {
            return new_node;
        }
        else
        {
            mininode(new_node->left);
        }
    }
    node* search(int value, node* new_node)
    {
        if (root == nullptr)
        {
            cout << "Tree Empty!!!\n";
            return nullptr;
        }
        else if (value == new_node->data)
        {
            cout << "Found !!!\n";
            return new_node;
        }
        else if (value > new_node->data)
        {
            search(value, new_node->right);
        }
        else if (value < new_node->data)
        {
            search(value, new_node->left);
        }
        else if (new_node == nullptr)
        {
            cout << "Value Not Found!!!\n";
            return new_node;
        }
    }
    void preOrder(node* new_node)
    {
        if (new_node == nullptr)
            return;
        cout << new_node->data << "  ";
        preOrder(new_node->left);
        preOrder(new_node->right);
    }

    void postOrder(node* new_node)
    {
        if (new_node == nullptr)
            return;
        postOrder(new_node->left);
        postOrder(new_node->right);
        cout << new_node->data << " ";
    }

    int menu(int opt)
    {
        if (opt == 0)
        {
            return -1;
        }
        else if (opt == 1)
        {
            node* new_node = new node;
            cout << "Enter Data in Node : ";
            cin >> new_node->data;
            insertNode(new_node);
            menu(-1);
        }
        else if (opt == 2)
        {
            int r;
            cout << "Enter Data to deleted : ";
            cin >> r;
            delete_node(root, r);
            menu(-1);
        }
        else if (opt == 3)
        {
            int r;
            cout << "Enter Data to be searched : ";
            cin >> r;
            search(r, root);
            menu(-1);
        }
        else if (opt == 4)
        {
            int oo;
            cout << "\nEnter Your Choice According to the Options Below: \n";
            cout << "1. To Display Tree in inOrder Traversal\n";
            cout << "2. To Display Tree in preOrder Traversal\n";
            cout << "3. To Display Tree in postOrder Traversal\n";
            cin >> oo;
            if (oo == 1)
                inOrder(root);
            else if (oo == 2)
                preOrder(root);
            else if (oo == 3)
                postOrder(root);
            else
                menu(4);
            menu(-1);
        }
        else
        {
            cout << "Enter Your Choice According to the Options Below: \n";
            cout << "0. To Exit\n";
            cout << "1. To Insert a Value\n";
            cout << "2. To Delete a Value\n";
            cout << "3. To Search a Value\n";
            cout << "4. To Display Full Tree\n";
            cin >> opt;
            menu(opt);
        }
    }
};


int main()
{
    BST b;
    b.menu(-1);
    return 0;
}
