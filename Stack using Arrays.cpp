#include<iostream>
using namespace std;
class stackarray
{
private:
	int *stack;
	int top;
	int size;
	int item;
public:
	stackarray(int size = 5)
	{
		top = -1;
		this->size = size;
		stack = new int[size];
		item = 0;
	}
	void push(int value)
	{
		//cout << " data for stack " << endl;
		if (top >= (size-1))
		{
			cout << " Stack overflows " << endl;
		}
		else
		{
			top++;
			stack[top] =value;
		}
	}
	void pop()
	{
		if (top <= -1)
		{
			cout << " Stack Underflows " << endl;
		}
		else
		{
			item = stack[top];
			top--;
			cout << "The pop value is " << item << endl;
		}
	}
	void peek()
	{
		if (top == -1)
		{
			cout << " Stack is empty " << endl;
		}
		else
		{
			cout << " The top element of the stack is " << stack[top] << endl;
		}
	}
	void display()
	{
		int i;
		for (int i = top; i >= 0; i--)
		{
			cout << " The elements of the stack are " << stack[i] << endl;
		}
	}
};
int main()
{
	int choice;
	stackarray s;
	cout << "Enter Data for stack:" << endl;
	for (int a = 0; a < 5; a++)
	{ 
		cin >> a;
		s.push(a);
	}
	do
	{
		cout << " ENTER YOU CHOICES WHAT YOU WANT TO DO WITH YOUR STACK " << endl;
		cout << "Press 0 for Exit " << endl;
		cout << "Press 2 for pop " << endl;
		cout << "Press 3 for peek " << endl;
		cout << "Press 4 for display the stack " << endl;
		cin >> choice;	
	     if(choice == 2)
		{
			s.pop();
		}
		else if (choice == 3)
		{
			s.peek();
		}
		else if(choice == 4)
		{
			s.display();
		}
		//default:
		//	cout << " Invalid Option !!!! " << endl;
		//	break;		
	} 
	while (!(choice == 0));
	return 0;
}

		

		




	