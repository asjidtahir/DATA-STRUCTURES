#include<iostream>

using namespace std;

class Arrayoperations 
{
	int *p1,*p2;
	int frequency ;
    int array[8]={2,2,3,3,3,4,5,6};
public:
       MostFrequentElementInSubArray()
	   { 
	      p1 = p2 = array ;
	       frequency=0;
		}		
	    void check()
	    {
	    	
	    	for(int a=0; a<8; a++)
	    	{
	    		for(int b=0; b<8; b++)
	    		{
	    		   if ((*p1)==(*p2))
	    		   {
	    		   	  frequency++;
				   }
				   p2++;
				}
			  cout << "Frequency  "<<*p1<<"is"<<frequency<<endl;
			  p2=array;
			  frequency=0;
			  p1++;
			}
		}
};


int main ()
{
	Arrayoperations Array;
	Array.MostFrequentElementInSubArray();
	
	system("pause");
	return 0;
}
