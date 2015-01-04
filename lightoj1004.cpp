#include<stdio.h>

long a[210][110],dp[210][210],row,n;

long max(long a,long b)
{
	if(a>b)
		return a;
	else 
		return b;
}

long rec(long i,long j)
{
	if(i<1||i>row||j<1||j>n)
		return 0;
	if(a[i][j]==0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	long p1,p2,mx;
	p1=rec(i+1,j);
	if(i>=n)
		p2=rec(i+1,j-1);
	else
		p2=rec(i+1,j+1);
	mx=max(p1,p2);
	return dp[i][j]=a[i][j]+mx;
}

int main()
{
	long t,x=1,i,j,b,sum,k;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		row=2*n-1;
		k=1;
		for(i=1;i<=row;i++)
		{
			if(i>=1&&i<=n)
			{
				for(j=1;j<=i;j++)
				{
					scanf("%ld",&a[i][j]);
					dp[i][j]=-1;
				}
				for(j=i+1;j<=n;j++)
				{
					a[i][j]=0;
					dp[i][j]=-1;
				}
			}
			else
			{
				for(j=1;j<=n-k;j++)
				{
					scanf("%ld",&a[i][j]);	
					dp[i][j]=-1;
				}
				for(b=j;b<=n;b++)
				{
					a[i][b]=0;
					
					dp[i][b]=-1;
				}
				k++;
			}
		}
		sum=rec(1,1);
		printf("Case %ld: %ld\n",x++,sum);
	}
	return 0;
}