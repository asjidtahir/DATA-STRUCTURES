#include<iostream>
using namespace std;
int main()
{
	const char* ch = "22222.222222222";
	int string_length = 0;
	int index_counter = 0;
	int i = 0;
	while (ch[i]!='0')
	{
		if (ch[i] == '.')
		{
			index_counter = index_counter + 0;
		}
		else
		{
			index_counter;
		}
	}
	cout << "The length of string is :: " << index_counter << endl;
	while (*ch != '.')
	{
		string_length ++;
		ch++;
	}
	cout << "index pos is :: " << string_length << endl;

	system("pause");
	return 0;
	//// YOUR CODE
}
