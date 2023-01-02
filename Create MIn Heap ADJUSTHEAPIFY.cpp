#include <iostream.h>
#include <conio.h>
class HEAP_MIN
{
	private:
		int*A,n;
	public:
		HEAP_MIN(int size);
		void READ();
		void ADJUST(int value, int n);
		void HEAPIFY();
		void DISPLAY();

};
HEAP_MIN :: HEAP_MIN(int size)
{
	n = size;
	A= new int[n+1];
}
void HEAP_MIN :: READ()
{
	for(int i=1; i<=n; i++)
	{
		cin>>A[i];
	}
}
void HEAP_MIN :: ADJUST(int value, int n)
{
	int j, item;
	j = 2*value;
	item = A[value];
	while(j<=n)
	{
		if(j < n && A[j] > A[j+1])
		{
			j = j + 1;
		}
		if(item < A[j])
			break;
		else
			A[j/2] = A[j];
		j = 2*j;
	}
	A[j/2] = item;
}
void HEAP_MIN :: HEAPIFY()
{
	for(int i= n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
void HEAP_MIN :: DISPLAY()
{
	for(int i=1; i<=n; i++)
	{
		cout<<A[i]<<" ";
	}
}
void main()
{
	clrscr();
	int size;
	cout<<"Enter the size of list: ";
	cin>>size;
	HEAP_MIN obj(size);
	obj.READ();
	cout<<"\nYou Entered Elements are: ";
	obj.DISPLAY();
	obj.HEAPIFY();
	cout<<"\nElements after Creating MIN_HEAP: ";
	obj.DISPLAY();
	getch();
}
