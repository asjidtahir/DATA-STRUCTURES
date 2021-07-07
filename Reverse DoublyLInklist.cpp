
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
class LinkedList
{
private:
	node* head;
	node* tail;

public:
	LinkedList()
	{
		head = NULL;
	}
	void insert(int Data)
	{
		node* NewNode = new node;
		NewNode->data = Data;
		NewNode->next = 0;
		NewNode->prev = 0;
		if (head == 0)
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
		while (tail != 0)
		{
			cout << tail->data << ",";
			tail = tail->next;
		}
		cout << endl;
	}
	void Reverse()
	{
		node* current = head;
		node* prev = NULL, * next = NULL;
		while (current != 0)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;

	}
};
int main()
{
	LinkedList L;
	L.insert(4);
	L.insert(2);
	L.insert(6);
	L.insert(8);
	L.Display();
	cout<<" The reverse of doublelinklist is \n";
	L.Reverse();
	L.Display();
	system("pause");
	return 0;
}