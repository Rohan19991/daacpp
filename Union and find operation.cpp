#include"iostream.h"
#include"conio.h"
class SET
{
		int n,*PAR;
	public:
		SET(int);
		void U(int,int);
		int F(int);
		void DISPLAY();
};
SET::SET(int par)
{
	n=par;
	PAR=new int[n+1];
	for(int i=1;i<=n;i++)
		PAR[i]=0;
}
void SET::U(int i,int j)
{
	PAR[i]=j;
}
int SET::F(int i)
{
	int j=i;
	while(PAR[j]>0)
		j=PAR[j];
	return j;
}
void SET::DISPLAY()
{
	cout<<"\nNODE\tPARENT\tWT";
	for(int i=1;i<=n;i++)
		cout<<endl<<i<<"\t"<<PAR[i];
}

void MENU()
{
	int opt,size,i,j;
	cout<<"\nEnter no of sets : ";
	cin>>size;
	SET obj(size);
	do
	{
		cout<<"\n1 Union";
		cout<<"\n2 Find";
		cout<<"\n3 DIsp";
		cout<<"\n4 Exit";
		cout<<"\nEnter your option : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\nEnter roots of two sets : ";
				cin>>i>>j;
				obj.U(i,j);
				break;
			case 2:
				cout<<"\nEnter ele to find : ";
				cin>>i;
				cout<<"\nRoot of "<<i<<" is "<<obj.F(i);
				break;
			case 3:
				obj.DISPLAY();
				break;
			case 4:
				return;
			default:
				cout<<"\ninvalid input";
				break;
		}
	}
	while(1);
}

void main()
{
	clrscr();
	MENU();
	getch();
}
