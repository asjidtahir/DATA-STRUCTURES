#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void Print(queue<char>& Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << ",";
        Queue.pop();
    }
}

void reverseQueue(queue<char>& Queue)
{
    stack<char> Stack;
    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

int main()
{
    queue<char> Queue;
    Queue.push('D');
    Queue.push('S');
    Queue.push('A');
    Queue.push(',');
    Queue.push('L');
    Queue.push('A');
    Queue.push('B');
    reverseQueue(Queue);
    Print(Queue);
    return 0;
}