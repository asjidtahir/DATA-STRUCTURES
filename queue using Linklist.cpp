#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class queue
{
private:
	node* rear;
	node* front;
	node* temp;
public:
	queue()
	{
		rear = NULL;
		front = NULL;
		temp = NULL;
	}
	void queue1(int x)
	{
		node* newnode;
		newnode = new node;
		newnode->data = x;
		newnode->next = NULL;
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is empty" << endl;
			front = rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void dequeue()
	{
		temp = front;
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			cout << "The dequeued element is " << front->data << endl;
			cout << endl;
			front = front->next;
			free(temp);
		}
	}
	void display()
	{
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			temp = front;
			while (temp != NULL)
			{
				cout << temp->data << endl;
				temp=temp->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	queue q;
	q.queue1(2);
	q.queue1(4);
	q.queue1(5);
	q.queue1(6);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
	system("pause");
	return 0;
}




		










