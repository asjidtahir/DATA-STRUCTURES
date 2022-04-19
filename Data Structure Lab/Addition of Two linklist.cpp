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
class ListList      
{
private:
	node* head;
	node* temp1;
public:
	ListList()
	{
		head = NULL;
		node* temp1 = new node;
	}
	void add(int info)    
	{
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
		cout << "The linklists are = " << endl;
		while (temp1 != NULL)
		{
			cout << temp1->info << "  ";
			temp1 = temp1->next;
		}
		cout << endl;
	}
};
class linkList2
{
private:
	node2* head1;
	node2* temp2;
public:
	linkList2()
	{
		head1 = NULL;
		node2* temp2 = new node2;
	}
	void add2(int data)
	{
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
		temp2 = head1;
		while (temp2 != NULL)
		{
			cout << temp2->data << "  ";
			temp2 = temp2->next1;
		}
		cout << endl;
	}
	void add_twolinklists(node* first, node* second)
	{
		int carry = 0;
		int sum;
		node* newNode = NULL;
		node* temp;
		node* addition = NULL;
		do
		{
			sum = carry + (first ? first->info : 0) + (second ? second->info : 0);
			carry = (sum >= 10) ? 1 : 0;
			sum = sum % 10;
			temp = newNode(sum);
			if (addition == NULL)
			{
				addition = temp;
			}
			else if (first)
			{
				first = first->next;
			}
			else if (second)
			{
				second = second->next;
			}
			if (carry > 0)
			{
				temp->next = newNode(carry);
				return addition;
			}
		} while (first != NULL || second != NULL);
	}
	void printList(node* node)
	{
		while (node != NULL)
		{
			cout << node->info << " , ";
			node = node->next;
		}
		cout << endl;
	}
};
int main()
{
	ListList bruh;
	bruh.add(1);
	bruh.add(2);
	bruh.add(3);
	bruh.add(4);
	bruh.print();
	linkList2 bruh2;
	bruh2.add2(1);
	bruh2.add2(1);
	bruh2.add2(1);
	bruh2.print2();
	node* addition = NULL;
	node* first = NULL;
	node* second = NULL;
	addition = add_twolinklists(first, second);
	cout << " The addition sum of two linklist are:" << endl;
	printList(addition);
	system("pause");
	return 0;
}
