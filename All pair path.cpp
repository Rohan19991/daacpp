#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class GRAPH
{
	private:
		int n,COST[10][10],A[10][10];
	public:
		GRAPH(int);
		void READ_GRAPH();
		void SHOW_GRAPH();
		void ALL_PAIR();
};
GRAPH::GRAPH(int par)
{
	n=par;
}
void GRAPH::READ_GRAPH()
{
	cout<<"\nEnter cost Matrix:";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>COST[i][j];
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<COST[i][j]<<" ";
	}
}
void GRAPH::SHOW_GRAPH()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<A[i][j]<<" ";
	}
}
int MIN(int a,int b)
{
	if(a<b) return a; else return b;
}
void GRAPH::ALL_PAIR()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			A[i][j]=COST[i][j];

	for(int k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				A[i][j]=MIN(A[i][j],A[i][k]+A[k][j]);

}
void main()
{
	int n;
	clrscr();
	cout<<"\nEnter no of nodes : ";
	cin>>n;
	GRAPH obj(n);
	obj.READ_GRAPH();
	obj.ALL_PAIR();
	obj.SHOW_GRAPH();
	getch();
}
