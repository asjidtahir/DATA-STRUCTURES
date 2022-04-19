#include<iostream>
using namespace std;
void length()
{
    char* ch = "22222.22222222";
	int string_length = 0;
	int index_counter = 0;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '.')
		{
			index_counter = index_counter + 0;
		}
		else
		{
			index_counter++;
		}
	}
	cout << "The length of string is :: " << index_counter << endl;
	while (*ch != '.')
	{
		string_length ++;
		ch++;
	}
	cout << " The index position  is : " << string_length << endl;
	
}
int main()
{
	length();
	system("pause");
	return 0;

}