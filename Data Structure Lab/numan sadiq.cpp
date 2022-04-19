#include<iostream>
using namespace std;
int target(int *t)
{
	return *t;
}
void arr(int target,int a[])
{
	
	int a[6]={2,3,5,6,7,8};
	cur_ptr=ptr;
	ptr=a;

	while(*a!='\0')
	{
		cur_ptr++;
		if(arr+arr->cur_ptr== target)
		a++;
	}
	for(int i=0;i<6;i++)
	{
		if(a[6]+a[7]==target)
		{
			cout<<"the values are :: "<<target<<endl;
		}

	}
}

int main()
{
	int a[6]={2,3,5,6,7,8};
	arr();
	system("pause");
	return 0;
}