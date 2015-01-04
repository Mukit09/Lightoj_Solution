#include<stdio.h>
#include<math.h>
#define si 110
#define min(a,b) (a<b?a:b)

double n,dp[si];
int a[si];

double rec(int ind)
{
	if(ind==n)
		return a[ind];
	if(dp[ind]!=-1)
		return dp[ind];
	double mx,sm=0,p;
	if(ind+6>n)
		mx=n;
	else
		mx=ind+6;
	int i;
	for(i=ind+1;i<=mx;i++)
	{
		sm=sm+(a[i]);
		if(i!=n)
		{
			p=rec(i);
			sm+=p;
		}
	}
	sm/=(mx-ind);
	return dp[ind]=sm;
}

int main()
{
	int t,x=1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		for(i=1;i<=n;i++)
		{
			dp[i]=-1;
			scanf("%d",&a[i]);
		}
		if(n==1)
			printf("Case %d: %d\n",x++,a[1]);
		else
			printf("Case %d: %lf\n",x++,rec(1)+a[1]);
	}
	return 0;
}