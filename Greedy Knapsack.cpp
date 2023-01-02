#include<iostream.h>
#include<conio.h>
class GREEDY
{
	private:
		int i,n;
		float M,Cu,*P,*W,*X,*R;
	public:
		GREEDY(float size, int par);
		void READ();
		void SORT();
		void KNAPSACK();
		void DISPLAY();
};
GREEDY :: GREEDY(float size,int par)
{
	M=size;
	n=par;
	P=new float[n+1];
	W=new float[n+1];
	X=new float[n+1];
	R=new float[n+1];
}
void GREEDY :: READ()
{
	for(i=1; i<=n; i++)
	{
		cout<<"Enter weight of product: ";
		cin>>W[i];
		cout<<"Enter Profit of Product: ";
		cin>>P[i];
	}
}
void GREEDY :: SORT()
{
	float temp;
	for(i=1;i<=n;i++)
	{
		R[i]=P[i]/W[i];
	}

	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(R[j] < R[j+1])
			{
				temp=R[j];
				R[j]=R[j+1];
				R[j+1]=temp;

				temp=P[j];
				P[j]=P[j+1];
				P[j+1]=temp;

				temp=W[j];
				W[j]=W[j+1];
				W[j+1]=temp;
			}
		}
	}
}
void GREEDY :: KNAPSACK()
{
	Cu = M;
	for(i=1;i<=n;i++)
	{
		if(W[i]> Cu)
			break;
		else
		{
			X[i] =1;
			Cu= Cu-W[i];
		}
	}
	if(i<=n)
	{
		X[i]= Cu/W[i];
	}

}
void GREEDY :: DISPLAY()
{
	float sum=0;
	for(i=1;i<=n;i++)
	{
		sum= sum + X[i]*P[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<" Weight "<<W[i]<<" "<<"Profit "<<P[i]<<" "<<" Ratio "<<R[i]<<" ";
		cout<<endl;
	}
	cout<<"Max Profit is: "<<sum<<endl;
	for(i=1;i<=n;i++)
		cout<<"solution vactor is : "<<X[i]<<" "<<endl;
}
void main()
{
	clrscr();
	int n;
	float size;
	cout<<"Enter Capacity of Knapsack Bag: ";
	cin>>size;
	cout<<"Enter No. of Products: ";
	cin>>n;
	GREEDY obj(size,n);
	obj.READ();
	obj.SORT();
	obj.KNAPSACK();
	obj.DISPLAY();
	getch();
}
