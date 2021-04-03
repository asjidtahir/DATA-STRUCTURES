#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class LinkedList
{
	struct node* head;
	struct node* temp; // to traverse through the whole list 
public:
	LinkedList()
	{
		head = NULL;
	}
	void insert()
	{
		node* NewNode = new node;
		cout << "Enter data :: ";
		cin >> NewNode->data;
		NewNode->next = 0;
		if (head == 0)
		{
			head = temp = NewNode;
		}
		else
		{
			temp->next = NewNode;
			temp = NewNode; 
		}
	}
	void InserAtBigening()
	{
		node* NewNode = new node;
		cout << "Enter data that you want to insert at start :: ";
		cin >> NewNode->data;
		NewNode->next = head;
		head = NewNode;
	}
	
	void InsertAtGivenPosition()
	{
		int pos;
		node* NewNode = new node;
		cout << "Enter the possition :: ";
		cin >> pos;
		temp = head;
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next;
		}
		cout << "Enter data :: ";
		cin >> NewNode->data;
		NewNode->next = temp->next;
		temp->next = NewNode;
	}
	void Display()
	{
		temp = head;
		cout << "The Liked List is :: ";
		while (temp != 0)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << endl;
	}
	void DellAtBeg()
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	
	
	
	void options()
	{
		int press;
		int choice;
		do
		{
			cout << "Press 1). to insert a node. !" << endl;
			cout << "Press 2). to Insert a node at Beginning. !" << endl;
			cout << "Press 3). to Insert a node at Last. !" << endl;
			cout << "Press 4). to Insert a node to a specific possition !" << endl;
			cout << "Press 5). to Delete a node at beginning !" << endl;
			cout << "Press 6). to Delete a node at the last !" << endl;
			cout << "Press 7). to Delete a node at a specific postion !" << endl;
			cout << "Press 8). to Display Linked List !" << endl;
			cout << "Press 9). to Display the Length of Linked List !" << endl;
			cout << "Press 10). to Exit !!!" << endl;
			cin >> press;
			if (press == 1)
			{
				insert();
				do
				{
					cout << "Press 1) to continue || Press 0) for stop !" << endl;
					cin >> choice;
					if (choice == 1)
					{
						insert();
					}
					else
					{
						cout << "Invalide choice" << endl;
					}
				} while (choice != 0);
			}
			else if (press == 2)
			{
				InserAtBigening();
			}
			
			else if (press == 4)
			{
				InsertAtGivenPosition();
			}
			else if (press == 5)
			{
				DellAtBeg();
			}
			
			
			else if (press == 8)
			{
				Display();
			}
			
			else if (press == 10)
			{
				return;
			}
			else
			{
				cout << "Invalid Condition !!!" << endl;
			}
		} while (press != 10);
	}
};
int main()
{
	LinkedList L;
	L.options();
	system("pause");
	return 0;
}
