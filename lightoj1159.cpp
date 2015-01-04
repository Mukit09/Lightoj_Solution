#include<stdio.h>
#include<string.h>
#define si 55
#define max(a,b) (a>b?a:b)
char ch1[si],ch2[si],ch3[si];
int l1,l2,l3,dp[si][si][si];

int rec(int i,int j,int k)
{
	if(i==l1||j==l2||k==l3)
		return 0;
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	if(ch1[i]==ch2[j]&&ch2[j]==ch3[k])
		return dp[i][j][k]=1+rec(i+1,j+1,k+1);
	else 
		return dp[i][j][k]=max(rec(i+1,j,k),max(rec(i,j+1,k),rec(i,j,k+1)));
}

int main()
{
	int t,x=1,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",ch1,ch2,ch3);
		l1=strlen(ch1);
		l2=strlen(ch2);
		l3=strlen(ch3);
		for(i=0;i<l1;i++)
		{
			for(j=0;j<l2;j++)
			{
				for(k=0;k<l3;k++)
					dp[i][j][k]=-1;
			}
		}
		printf("Case %d: %d\n",x++,rec(0,0,0));
	}
	return 0;
}