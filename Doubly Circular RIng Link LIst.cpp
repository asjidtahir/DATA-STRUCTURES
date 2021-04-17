#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
class Doubly_Circular_LinkedList
{
private:
	node* head;
	node* tail;

public:
	Doubly_Circular_LinkedList()
	{
		head = NULL;

	}
	void insert(int Data)
	{
		node* NewNode = new node;
		NewNode->data = Data;
		NewNode->next = NULL;
		NewNode->prev = NULL;
		if (head == NULL)
		{
			head = tail = NewNode;
		}
		else
		{
			tail->next = NewNode;
			NewNode->prev = tail;
			tail = NewNode;
		}
	}
	void Display()
	{
		tail = head;
		cout << "The Doubly linked list is :: ";
		while (tail != NULL)
		{
			cout << tail->data << ",";
			tail = tail->next;
		}
		cout << endl;
	}
	void AddAtBeginnign()
	{

		tail = head;
		node* NewNode = new node;
		cout << "Enter data that you want to insert at beginning :: ";
		cin >> NewNode->data;
		NewNode->next = NULL;
		NewNode->prev = NULL;
		if (head == NULL)
		{
			head = tail = NewNode;
		}
		else
		{
			head->prev = NewNode;
			NewNode->next = head;
			head = NewNode;
		}
	}
	void InsertAtLast()
	{
		tail = head;
		node* NewN = new node;
		cout << "Enter data that you want to insert at Last :: ";
		cin >> NewN->data;
		NewN->prev = NULL;
		NewN->next = NULL;
		if (head == NULL)
		{
			head = tail = NewN;
		}
		else
		{
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = NewN;
			NewN->prev = tail;
			tail = NewN;
		}
	}
	void InsertAtSpecificPosition()
	{
		tail = head;
		int pos;
		node* NewNode = new node;
		cout << "Enter the position  :: ";
		cin >> pos;
		if (head == NULL)
		{
			head = tail = NewNode;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				tail = tail->next;
			}
			cout << "Enter value of node :: ";
			cin >> NewNode->data;
			NewNode->next = tail->next;
			NewNode->prev = tail;
			tail->next = NewNode;
			tail = NewNode;
		}
	}

	//- -----------------------------DELL Operations--------------------------------
	void DellAtBeg()
	{

		tail = head;
		node* temp;
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else if (head->next == NULL)
		{
			head = NULL;
			delete head;
		}
		else
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			cout << "first node is deleted" << endl;
		}
	}
	void DellAtLast()
	{
		node* temp;
		tail = head;
		if (head == NULL)
		{
			cout << "List is empty " << endl;
		}
		else
		{
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			temp = tail;
			tail->prev->next = NULL; //mean (next part of 2nd last node in the list is zero)
			tail = tail->prev;
			delete temp;
			cout << "Last node deleted" << endl;
		}
	}
	void DellAtSpecificPosition()
	{
		tail = head;
		node* temp;
		temp = head;
		int pos;
		cout << "Enter the position from which do you want to remove data :: ";
		cin >> pos;
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next;  
			temp->next->prev = temp->prev;  
			delete temp;
		}
	}
};
int main()
{
	Doubly_Circular_LinkedList L;
	L.insert(4);
	L.insert(1);
	L.insert(3);
	L.insert(7);
	L.Display();
	L.AddAtBeginnign();
	L.Display();
	L.InsertAtLast();
	L.Display();
	L.InsertAtSpecificPosition();
	L.Display();
	L.DellAtBeg();
	L.Display();
	L.DellAtLast();
	L.Display();
	L.DellAtSpecificPosition();
	L.Display();
	return 0;
}


