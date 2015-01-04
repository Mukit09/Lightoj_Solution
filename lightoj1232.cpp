/*
// Gave TLE
#include<stdio.h>
#define mod 100000007

long n,k,x=1,t,coin[110],dp[110][10010],count;

long rec(long i,long taken)
{
	if(i>n)
	{
		if(taken==k)
			return 1;
		else return 0;
	}
	if(taken==k)
		return 1;
	else if(taken>k)
		return 0;
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	long p=0,j;
	for(j=1;j<=k;j++)
	{
		if(taken+coin[i]*j)
			p+=rec(i+1,taken+coin[i]*j)%mod;
		else break;
	}
	p+=rec(i+1,taken)%mod;
	dp[i][taken]=p%mod;
	return dp[i][taken];
}

int main()
{
	long i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&coin[i]);
			for(j=0;j<=k;j++)
				dp[i][j]=-1;
		}
		count=rec(1,0)%mod;
		printf("Case %ld: %ld\n",x++,count);
	}
	return 0;
}*/

/*
//Gave TLE
#include<stdio.h>
#define mod 100000007

long cnt,k,x=1,coin[110],n,t,sum,dp[110][10010];

long rec(long i,long taken)
{
	if(taken>k)
		return 0;
	if(taken==k)
		return 1;
	if(i>n)
	{
		if(taken==k)
			return 1;
		else
			return 0;
	}
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	long p1=0,p2=0;
	if(taken+coin[i]<=k)
		p1=rec(i,taken+coin[i]);
	p2=rec(i+1,taken);
	dp[i][taken]=(p1%mod+p2%mod)%mod;
	return dp[i][taken];
}

int main()
{
	long i,j,re;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&coin[i]);
		for(j=0;j<=k;j++)
			dp[i][j]=-1;
		}
		re=rec(1,0);
		printf("Case %ld: %ld\n",x++,re);
	}
	return 0;
}*/

#include<stdio.h>
#define mod 100000007

long n,i,j,k,x,nway[10010],coin[110],t,y=1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		for(i=1;i<=k;i++)
			nway[i]=0;
		nway[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&coin[i]);
			for(j=coin[i];j<=k;j++)
			{
				x=j-coin[i];
				nway[j]=(nway[x]%mod+nway[j]%mod)%mod;
			}
		}
		printf("Case %ld: %ld\n",y++,nway[k]%mod);
	}
	return 0;
}
		