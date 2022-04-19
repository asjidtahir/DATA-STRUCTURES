#include<iostream>
using namespace std;
struct node
{
	int info;
	node* next;
};
struct node2
{
	int data;
	node2* next1;
};
struct node3
{
	int num;
	node* next3;
};
class List
{
private:
	node* head;
	node* temp1;
	node* current1;
	node2* head1;
	node2* temp2;
	node2* current2;
	node3* head3;
	node3* temp3;
	node3* current3;
	int num;
public:
	List()
	{
		temp1 = NULL;
		temp2 = NULL;
		current1 = NULL;
		current2 = NULL;
		current3 = NULL;
		num = 0; //n
		head = NULL;
		node* temp1 = new node;
		head1 = NULL;
		node2* temp2 = new node2;
	}
	void add(int info)
	{
		temp1 = head;
		current1 = temp1;
		node* newnode = new node;
		newnode->info = info;
		newnode->next = NULL;
		if (head == NULL)
		{
			head = temp1 = newnode;
		}
		else
		{
			temp1->next = newnode;
			temp1 = newnode;
		}
	}
	void print()
	{
		temp1 = head;
		current1 = head;
		cout << "The given link lists which we want to add are  :" << endl;
		while (temp1 != NULL)
		{
			cout << temp1->info << "  ";
			temp1 = temp1->next;
		}
		cout << endl;
	}
	void add2(int data)
	{
		current2 = head1;
		node2* new_node = new node2;
		new_node->data = data;
		new_node->next1 = NULL;
		if (head1 == NULL)
		{
			head1 = temp2 = new_node;
		}
		else
		{
			temp2->next1 = new_node;
			temp2 = new_node;
		}
	}
	void print2()
	{
		current2 = head1;
		temp2 = head1;
		
		while (temp2 != NULL)
		{
			cout << temp2->data << "  ";
			temp2 = temp2->next1;
		}
		cout << endl;
	}

	void addition()
	{
		cout << "ADdition :" << endl;
		int carry=0 ,remender=0,sum=0;
		node3* Newnode = new node3;
		sum = current1->info + current2->data;  //errored statement : I am just wanting to add values of every with other 
		remender = sum / 10;
		if (remender == 0) {
			Newnode->num = sum;
		}
		else if (remender != 0)
		{
			Newnode->num = remender;
		}		
	}
};

int main()
{
	List foo,foo2;
	foo.add(3);
	foo.add(2);
	foo.add(5);
	foo.add(9);
	foo.print();	
	foo2.add2(4);
	foo2.add2(2);
	foo2.add2(3);
	foo2.add2(1);
	foo2.print2();
	foo2.addition();
	return 0;
}