#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
class STRING
{
   private:
		char stk[10],str1[50],str2[50],B[20][20];
		int top,m, n,C[20][20];

		//int n,A[10][10];
   public:
		STRING();
		void READ_STRING();
		void SHOW_STRING();
		void LCS_LENGTH();
		void LCS_PRINT();
};
STRING::STRING()
{
	top=0;

}
void STRING::READ_STRING()
{
	 cout<<"\nEnter first string : ";
	 cin>>str1;
	 m=strlen(str1)-1;
	 cout<<"\nEnter 2nd string : ";
	 cin>>str2;
	 n=strlen(str2)-1;
}
void STRING::SHOW_STRING()
{
   cout<<endl;
   cout<<str1;
   cout<<endl;
   cout<<str2;
}
void STRING::LCS_LENGTH()
{
	for(int i=0;i<=n;i++)
		C[0][i]=0;
	for(i=0;i<=m;i++)
		C[i][0]=0;
	//----------------------
	for(i=1;i<=m;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
		{
			if(str1[i]==str2[j])
			{
				C[i][j] = C[i-1][j-1] + 1;
				B[i][j] = '\\';
			}
			else
				if(C[i-1][j] >= C[i][j-1])
				{
					C[i][j]=C[i-1][j];
					B[i][j] = '|';
				}
				else
				{
					C[i][j]=C[i][j-1];
					B[i][j] = '-';
				}
			cout<<B[i][j]<<"  ";
		}
	}

}
void STRING::LCS_PRINT()
{
	for(int i=m;i>=1;i--) //rows
		for(int j=n;j>=1;j--)//column
		{
			if(B[i][j]=='\\')
			{
				top=top+1;
				stk[top]=str1[i];
				i=i-1;
			}
			else
				if(B[i][j]=='|')
					i=i-1;
		}
	for(i=top;i>=1;i--)
		cout<<stk[i]<<" ";

}
void main()
{
   clrscr();
   STRING obj;
   obj.READ_STRING();
   obj.SHOW_STRING();
   obj.LCS_LENGTH();
   obj.LCS_PRINT();
   getch();
}
