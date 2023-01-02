#include"iostream.h"
#include"conio.h"
#include"stdlib.h"
#include"timer.h"
class LIST
{
		int n,*A;
	public:
		LIST(int);
		void SORT();
		void BIN_SRCH(int,int &);
		void BIN_SRCH1(int,int &);
		void DISPLAY();
};
LIST::LIST(int par)
{
	n=par;
	A=new int[n+1];
	for(int i=1;i<=n;i++)
		A[i]=random(1000);
}
void LIST::BIN_SRCH(int x,int &j)
{
	int low,high,mid;
	low=1;high=n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x < A[mid])
			high=mid-1;
		else
			if(x > A[mid])
				low=mid+1;
			else
			{
				j=mid;
				return;
			}
	}

}
void LIST::BIN_SRCH1(int x,int &j)
{
	int low,high,mid;
	low=1;high=n+1;
	while(low<high-1)
	{
		mid=(low+high)/2;
		if(x < A[mid])
			high=mid;
		else
			low=mid;
	}
	if(x==A[low])
		j=low;
	else
		j=0;

}
void LIST::DISPLAY()
{
	cout<<"\n List ele are :\n";
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void LIST::SORT()
{
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if( A[j]>A[j+1] )
			{
				int t=A[j];A[j]=A[j+1];A[j+1]=t;
			}
}
void main()
{
	Timer T;
	int x,size,pos;
	cout<<"\nEnter size of list : ";
	cin>>size;
	LIST obj(size);
	clrscr();
	obj.DISPLAY();
	obj.SORT();
	obj.DISPLAY();
	cout<<"\nEnter ele to srch : ";
	cin>>x;
	T.start();
	obj.BIN_SRCH1(x,pos); 
	T.stop();
	if(pos)
		cout<<"\nele "<<x<<" is found at "<<pos;
	else
		cout<<"\nele not found ";
	cout<<"\nTime taken to search is "<<T.time();
	getch();
}
