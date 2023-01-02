#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class LIST
{
	private:
			int *A,n;
	public:
		LIST(int);
		void READ();
		void DISPLAY();
		void MAXMIN(int,int,int&,int&);

};
LIST::LIST(int par)
{
		n=par;
		A=new int[n+1];
}
void LIST::READ()
{
	for(int i=1;i<=n;i++)
		A[i]=random(999);
}
void LIST::DISPLAY()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
}
void LIST::MAXMIN(int p,int q,int &max,int &min)
{
	int fmax,fmin,hmax,hmin;
	if(p==q)
		max=min=A[p];
	else
	{
		if(p==q-1)
		{
			if(A[p]>A[q])
			{
				max=A[p];min=A[q];
			}
			else
			{
				max=A[q];min=A[p];
			}
		}
			else
			{
				int m=(p+q)/2;
				MAXMIN(p,m,fmax,fmin);
				MAXMIN(m+1,q,hmax,hmin);
				if(fmax>hmax)
					max=fmax;
				else
					max=hmax;
				if(fmin<hmin)
					min=fmin;
				else
					min=hmin;
			}
	}
}
void main()
{
	clrscr();
	int size,max,min;
	cout<<"Enter the size of list: ";
	cin>>size;
	LIST obj(size);
	cout<<"You entered elements are:";
	obj.READ();
	obj.DISPLAY();
	obj.MAXMIN(1,size,max,min);
	cout<<"\n\n Max ="<<max<<"\t Min ="<<min;
	getch();
}
