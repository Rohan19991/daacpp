#include <iostream.h>
#include <conio.h>
class INSERT_MAX
{
	private:
		int*A,n;
	public:
		INSERT_MAX(int size);
		void READ();
		void INSERT(int);
		void CREATE_HEAP();
		void DISPLAY();

};
INSERT_MAX :: INSERT_MAX(int size)
{
	n = size;
	A= new int[n+1];
}
void INSERT_MAX :: READ()
{
	for(int i=1; i<=n; i++)
	{
		cin>>A[i];
	}
}
void INSERT_MAX :: INSERT(int node)
{
	int j, i, item;
	j = node; i= node/2; item = A[node];
	while(i > 0 && A[i] < item)
	{
		A[j] = A[i];
		j=i;
		i=i/2;
	}
	A[j] = item;
}
void INSERT_MAX :: CREATE_HEAP()
{
	for(int i= 2; i<=n; i++)
	{
		INSERT(i);
	}
}
void INSERT_MAX :: DISPLAY(){
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
	INSERT_MAX heap(size);

	heap.READ();
	cout<<"\nYou Entered Elements are: ";
	heap.DISPLAY();

	heap.CREATE_HEAP();
	cout<<"\nElements after Creating MAX_HEAP: ";
	heap.DISPLAY();
	getch();
}
