#include<iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};

class LinkedList
{
private:
	node* head, * temp, * temp2; //head will always point to first element, temp and temp2 will be used for moving and adding new nodes in the list
public:
	LinkedList() 
	{
		head = NULL;
		temp = NULL;
		temp2 = NULL;
	}
	//you can take value using user input within function or by passing value to the add function using a parameter
	//assuming you will use user input within function
	void add()
	{
		cout << " Enter data for the list \n";
		//code for checking whether the first element exists or not
		//if 1st element doesn't exists, write code to create 1st element
		//first element will always be pointed by head pointer
		node* new_node = new node;//uninitialize memory allocated and return void pointer
		cin >> new_node->value;
		new_node->next = NULL;
		if (head == NULL)
		{
			cout << " List is empty \n ";
			head = temp = new_node;
		}
		//create a new node
		//assign it a value
		//make it's next pointer null
		//the newly created node will be poined by the next pointer of last node
		//your code goes here
		else
		{
			temp->next = new_node;
			temp = new_node;

		}
	}
	//function to add a new value after an existing value
	//you can take value using user input within function or by passing value to the add function using a parameter
	//assuming you will use user input within function
	void addAfterSomeValue()
	{
	//write code to find the value after which you want to add the new value
	//assign the address of the next pointer of the node which is pointed by temp to the next pointer of newly created node
	int pos;
	//create a new node,assign it value
	node *NewNode= new node; //Dynamic Memory Allocation
	cout << endl;
	cout<<"Enter the position where you want to insert a value :\n ";
	cin>>pos;
	//your code goes here
	temp=head;
	for(int i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	cout << endl;
	cout<<"Enter value you want \n ";
	cin>>NewNode->value;
	//assign the address of newly created node to the next pointer of node pointed by temp
	NewNode->next=temp->next;
	temp->next=NewNode;
	}
	void del_1st()
	{
		struct node* temp2;
		int pos;
		temp = head;
	//check whether the list is empty or not, if list is empty, prompt a message and return
	//your code goes here
		if (head == NULL)
		{
			cout << " List empty \n";
			return;
		}
		cout << endl;
		cout << "Enter the position for which do you want to delete : \n";
		cin >> pos;
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
	}
	//Printing of linklist function
	void print()
	{ //function to print all the values of the list
		//your code goes here
		temp = head;
		while (temp != NULL)
		{
			cout << temp->value << ",";
			temp = temp->next;
		}
		
	}
};
void main()
{
	LinkedList obj;
	obj.add();//1
	obj.add();//2
	obj.add();//3
	obj.add();//4
	cout << " Your Linked List is \n " << "\n";
	obj.print();
	obj.addAfterSomeValue();//3
	cout << endl;
	cout << " One addition \n";
	obj.print();
	obj.addAfterSomeValue();
	obj.print();
	cout << "\n Deletetion " << endl;
	obj.del_1st();
	obj.print();
	cout << " Second deletion\n";
	obj.del_1st();
	obj.print();
	cout << " Third deletion \n";
	obj.del_1st();
	obj.print();
	system("pause");
}
