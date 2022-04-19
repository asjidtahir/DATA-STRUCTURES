#include<iostream>
using namespace std;
struct node     //Structure
{
	int info;
	node* next;
};
class List      //Class
{
private:
	node* head;
	node* temp1;
public:
	List()
	{
		cout << "Default Constructor Created:" << endl;
		head = NULL;
		node* temp1 = new node;
	}
	void add (int info)    //Adding
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
	void print()      //Printing
	{
		temp1 = head;
		cout << "The given link list is :" << endl;
		while (temp1 != NULL)
		{
			cout << temp1->info << "  ";
			temp1 = temp1->next;
		}
		cout << endl;
	}
	void Search()    
	{
		int num;
		temp1 = head;
		cout << " Enter the element you want :" << endl;
		cin >> num;
		while (temp1 != NULL)
		{
			if (temp1->info > num)
			{
				cout << temp1->info << endl;
				break;
			}
			temp1 = temp1->next;
			break;
		}
		cout << endl;
	}
};
int main()
{
	List foo;
	foo.add(4);
	foo.add(2);
	foo.add(5);
	foo.add(9);
	foo.print();
	foo.Search();
	return 0;
}