#include<stdio.h>
#define mod 100000007

long cnt[55],coin[55],dp[55][1010],k,n;

long rec(long i,long taken)
{
	if(i>n)
	{
		if(k==taken)
			return 1;
		else
			return 0;
	}
	if(taken>k) 
		return 0;
	if(taken==k)
		return 1;
	if(dp[i][taken]!=-1)
		return dp[i][taken];

	long p=0,j;
	for(j=1;j<=cnt[i];j++)
	{
		if(taken+coin[i]*j<=k)
			p+=rec(i+1,taken+coin[i]*j)%mod;
		else
			break;
	}
	p+=rec(i+1,taken)%mod;
	dp[i][taken]=p%mod;
	return dp[i][taken];
}

int main()
{
	long t,i,j,x=1,count;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%ld",&coin[i]);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&cnt[i]);
			for(j=0;j<=k;j++)
				dp[i][j]=-1;
		}
		count=rec(1,0)%mod;
		printf("Case %ld: %ld\n",x++,count);
	}
	return 0;
}