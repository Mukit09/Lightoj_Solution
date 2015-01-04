#include<stdio.h>
#include<math.h>

double dp[100010];

double rec(int v)
{
	if(v==1)
		return 0;
	if(dp[v]!=-1)
		return dp[v];
	int l=sqrt(v),i,cnt=2,j;
	double p=2;
	for(i=1;i<=l;i++)
	{
		if(i==1)
			continue;
		if(v%i==0)
		{
			j=v/i;
			p+=(rec(i)+1)
				;
			cnt++;
			if(i!=j)
			{
				cnt++;
				p+=(rec(j)+1);
			}
		}
	}
	return dp[v]=p/(double)(cnt-1);
}


int main()
{
	int t,x=1,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			dp[i]=-1;
		printf("Case %d: %lf\n",x++,rec(n));
	}
	return 0;
}