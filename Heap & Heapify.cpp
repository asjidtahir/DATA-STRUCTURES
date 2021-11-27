//CBT to max_heap
#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i) //n=size of heap,i=insert key
{
	int largest=i;  //largest is root of any tree || subtree
	int left=(2*i)+1;
	int right=(2*i)+2;
	if((left<n) && (arr[left]>arr[largest])) //when left is large then root
	{
		largest=left;
	}
	if((right<n) && (arr[right]>arr[largest]))
	{
		largest=right;
	}
	if(largest != i)  //If largest is not root
	{
		swap(arr[i], arr[largest]); 
		heapify(arr,n,i);
	}
}
void buildHeap(int arr[], int n)
{
	int start_index_of_tree = (n/2) -1;   //parent would be at
	for(int i=start_index_of_tree;i >= 0;i--)
	{
		heapify(arr,n,i);
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<",";
	}
	cout<<endl;
}
int main()
{
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
//				   1
//              /     \
//            3         5
//         /    \      /  \
//        4      6    13  10
//       / \    /  \
//      9   8  15   17
    int n = sizeof(arr) / sizeof(arr[0]); 
    buildHeap(arr, n); 
    print(arr, n);
//                 17
//              /      \
//            15         13
//          /    \      /  \
//         9      6    5   10
//        / \    /  \
//       4   8  3    1 
    return 0;
}
