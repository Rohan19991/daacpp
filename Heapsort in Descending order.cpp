#include <iostream.h>
#include <conio.h>
class HEAPSORT
{
	private:
		int*A,n;
	public:
		HEAPSORT(int size);
		void READ();
		void ADJUST(int node, int n);
		void HEAPIFY();
		void DISPLAY();
		void HSORT();
};
HEAPSORT :: HEAPSORT(int size)
{
	n = size;
	A= new int[n+1];
}
void HEAPSORT :: READ()
{
	for(int i=1; i<=n; i++)
	{
		cin>>A[i];
	}
}
void HEAPSORT :: ADJUST(int node, int n)
{
	int j, item;
	j = 2*node;
	item = A[node];
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
void HEAPSORT :: HEAPIFY()
{
	for(int i= n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
void HEAPSORT :: HSORT()
{
	for(int i = n; i>=2; i--)
	{
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		ADJUST(1,i-1);
	}
}
void HEAPSORT :: DISPLAY()
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
	HEAPSORT obj(size);
	obj.READ();
	obj.HEAPIFY();
	obj.HSORT();
	cout<<"\n\nElements after HEAPSORT: ";
	obj.DISPLAY();
	getch();
}
