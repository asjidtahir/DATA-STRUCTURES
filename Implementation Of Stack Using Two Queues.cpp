#include<iostream>
#include<queue>
using namespace std;
class Stack
{
private:
	queue<int> q1, q2, q;

public:

	int push(int val) 
	{
		q1.push(val);
		cout << "pushed :" << val << endl;
		return 1;
	}

	int pop()
	{
		if (q1.empty()) 
		{
			cout << "pop: stack is empty" << endl;
			return -1;
		}
		while (q1.size() > 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int e = q1.front();
		q1.pop();
		q = q1;
		q1 = q2;
		q2 = q;
		cout << "pop :" << e << endl;
		return e;
	}


	int top() 
	{
		if (q1.empty()) 
		{
			cout << "top: stack is empty" << endl;
			return -1;
		}
		int e;
		while (!q1.empty())
		{
			e = q1.front();
			q2.push(e);
			q1.pop();
		}
		q = q1;
		q1 = q2;
		q2 = q;
		cout << "top :" << e << endl;
		return e;
	}

	bool isEmpty() 
	{
		if (q1.size() == 0) 
		{
			return true;
		}
		return false;
	}


	int size() 
	{
		cout << q1.size() << endl;
		return 1;
	}

};

int main(void) 
{
	Stack s;
	s.push(10);
	s.push(11);
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.push(20);
	s.push(12);
	s.size();
	s.top();
	return 0;
}
