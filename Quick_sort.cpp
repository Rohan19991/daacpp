#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<timer.h>

void QUICK_SORT(int *arr,int low,int high)
{
	int pivot,temp,i,j;
	if(low<high)
	{
		pivot=arr[low];
		i=low+1;
		j=high;
		while(i<j)
		{
			while(arr[i]<pivot && i<=high)
			i++;
			while(arr[j]>pivot && j>low)
			j--;
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		arr[low]=arr[j];
		arr[j]=pivot;
		QUICK_SORT(arr,low,j-1);
		QUICK_SORT(arr,j+1,high);
	}
}
void main()
{
	clrscr();
	Timer T;
	int n,arr[1000];
	cout<<"\n Enter the size of array : ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		arr[i]=random(1000);
	}
	T.start();
	QUICK_SORT(arr,1,n);
	T.stop();
	cout<<"\n After Quick Sorting Elements : ";
	for(i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n Exact time of Execution : "<<T.time();
	getch();

}
