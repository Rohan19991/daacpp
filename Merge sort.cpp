#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<timer.h>
int arr[1000];
void MERGE(int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	int brr[1000];
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
		    brr[k]=arr[i];
		    i++;
		}
		else
		{
		    brr[k]=arr[j];
		    j++;
		}
		k++;
	}
	while(i<=mid)
	{
	    brr[k]=arr[i];
	    i++;
	    k++;
	}
	while(j<=high)
	{
	    brr[k]=arr[j];
	    j++;
	    k++;
	}
	for(k=low;k<=high;k++)
	{
	     arr[k]=brr[k];
	}
}

void MERGE_SORT(int low,int high)
{
      if(low!=high)
      {
	int mid=(low+high)/2;
	MERGE_SORT(low,mid);
	MERGE_SORT(mid+1,high);
	MERGE(low,mid,high);
      }
}

void main()
{
	clrscr();
	Timer T;
	int n;
	cout<<"Enter size of an array : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    arr[i]=random(1000);
	}
	T.start();
	MERGE_SORT(0,n-1);
	T.stop();
	cout<<"After sorted Elements : "<<endl;
	for(i=0;i<n;i++)
	{
	   cout<<arr[i]<<"\t";
	}
	cout<<"\n Exact time of Execution : "<<T.time();
	getch();
}
