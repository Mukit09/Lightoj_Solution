#include<stdio.h>
#define inf 300000

long dp[30][5],j,n,col[30][5],fg;

long rec(long i,long j)
{
	if(i>n)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	long p,mn=inf,k;

	for(k=1;k<=3;k++)
	{
		if(k!=j||fg==1)
		{
			fg=0;
			p=col[i][k]+rec(i+1,k);
			if(p<mn)
				mn=p;
		}
	}
	dp[i][j]=mn;
	return dp[i][j];
}

int main()
{
	long t,i,re,j,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				dp[i][j]=-1;
				scanf("%ld",&col[i][j]);
			}
		}
		fg=1;
		re=rec(1,1);
		printf("Case %ld: %ld\n",k++,re);
	}
	return 0;
}