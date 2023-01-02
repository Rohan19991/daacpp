#include<iostream.h>
#include<conio.h>
class GRAPH
{
	private:
		int COST[10][10],DIST[10],n,v;
	public:
		GRAPH(int);
		void READ();
		void DISPLAY();
		void SHOW_DIST();
		void SHORTEST_PATH(int);
};
GRAPH:: GRAPH(int size)
{
	n=size;
}
void GRAPH:: READ()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>COST[i][j];
		}
	}
}
void GRAPH:: DISPLAY()
{
	for(int i=1;i<=n;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
		{
			cout<<COST[i][j]<<" ";
		}
	}
}
void GRAPH:: SHOW_DIST()
{
	cout<<"\n Source \t Destination \t Dist ";
	for(int k=1;k<=n;k++)
	{
		cout<<" "<<v<<"\t"<<k<<"\t"<<DIST[k]<<"\n";
	}
}
void GRAPH:: SHORTEST_PATH(int v)
{
	int s[10];
	for(int i=1;i<=n;i++)
	{
		s[i]=0;DIST[i]=COST[v][i];
	}
	s[v]=1;DIST[v]=0;
	for(int num=2;num<=n-1;num++)
	{
		int w,u,min=9999;
		for(w=1;w<=n;w++)
		{
			if(s[w]==0 && DIST[w]<min)
			{
				min=DIST[w];
				u=w;
			}
		}
		s[u]=1;
		for(w=1;w<=n;w++)
		{
			if(s[w]==0)
			{
				if(DIST[w]<DIST[u]+COST[u][w])
					DIST[w]=DIST[w];
				else
					DIST[w]=DIST[u]+COST[u][w];
			}
		}
	}

}
void main()
{
	clrscr();
	int size;
	cout<<"\n Enter the Number of Node \t";
	cin>>size;
	GRAPH g(size);
	cout<<"\n Enter Nodes for Graph \t";
	g.READ();
	cout<<"\n Your Graph is \n";
	g.DISPLAY();
	g.SHORTEST_PATH(1);
	g.SHOW_DIST();
	getch();
}
