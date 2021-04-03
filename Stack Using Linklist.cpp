#include <iostream>
#include<string>
using namespace std;
struct node
{
	int   data;
	node* next;
	node* top;
};
class staack
{
private:
	node* top;
	node* temp;
	//int   size;
public:
	staack()
	{
		temp = NULL;
		top = NULL;
	}

	void push(int info)
	{
		node* newnode;
		newnode = new node;
		newnode->data = info;
		newnode->next = top;
		top = newnode;
	}
	void display()
	{
		temp = top;
		if (top == NULL)
		{
			cout << "Stack is empty " << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void pop()
	{
		temp = top;
		if (top == NULL)
		{
			cout << "Underflows " << endl;
		}
		else
		{
			cout << "The pop elements is " << top->data << endl;

			top = temp->next;
			delete temp;
			temp = NULL;
		}
	}
	void peek()
	{
		if (top == NULL)
		{
			cout << " Stack is empty " << endl;
		}
		else
		{
			cout << "The top element of the stack is " << top->data << endl;
		}
	}
};
int main()
{

	staack s;
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << "Stack is " << endl;
	s.display();
	s.peek();
	s.pop();
	s.peek();
	cout << "Stack is " << endl;
	s.display();
	s.pop();
	s.peek();
	cout << "Stack is " << endl;
	s.display();
	s.peek();
	s.pop();
	cout << "Stack is " << endl;
	s.display();
	system("pause");
	return 0;
}