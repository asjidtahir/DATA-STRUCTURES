#include<iostream>
using namespace std;
class Array
{
public:
	int num[8];
	int* ptr;
	int M_counter;
	int x, y,count;
public:
	Array()    //Default Constructor Created
	{
		ptr = num;
		M_counter = 0;
		count = 1;
	}
	void Array_decleration()  //Decleration
	{
		*(num + 0) = 0;
		*(num + 1) = 1;
		*(num + 2) = 2;
		*(num + 3) = 3;
		*(num + 4) = 5;
		*(num + 5) = 7;
		*(num + 6) = 9;
		*(num + 7) = 7;
		//cout << " Our Array is :"<<endl;
		for (M_counter = *num, x = 0; x < 8; x++)
		{
			cout << *(num + x) << ",";
		}
		cout << endl;
	}
	void freq() // Frequency
	{
		for (x = 0; x < 8; x++)
		{
			count = 1;
			for (y = 0; y < 8; y++)
			{
				if (*(num + x) == *(num + y))
				{
					count++;
				}
				if (count > M_counter)
				{
					M_counter = count;
				}
			}
		}
		for (x = 0; x < 8; x++)
		{
			count = 1;
			for (y = 0; y < 8; y++)
			{
				if (*(num + x) == *(num + y))
				{
					count++;
				}
			}
			if (count == M_counter)
			{
				cout << *(num + x) << ",";
			}
		}
		cout << endl;
	}
};
int main()
{
	Array foo;
	foo.Array_decleration();
	foo.freq();
	system("pause");
	return 0;
}