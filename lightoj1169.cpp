#include<stdio.h>
#include<math.h>
#define si 1001
#define min(a,b) (a<b?a:b)
#define inf 9999999
int a1[si],a2[si],h1[si],h2[si],dp[si][3],n;

int rec(int i,int col)
{
	if(i==n)
	{
		if(col==1)
			return a1[i];
		else
			return a2[i];
	}
	if(dp[i][col]!=-1)
		return dp[i][col];
	int p,q;
	if(col==1)
	{
		p=a1[i]+rec(i+1,1);
		q=a1[i]+h1[i]+rec(i+1,2);
	}
	else
	{
		p=a2[i]+rec(i+1,2);
		q=a2[i]+h2[i]+rec(i+1,1);
	}
	return dp[i][col]=min(p,q);
}

int main()
{
	int t,x=1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			dp[i][1]=dp[i][2]=-1;
			scanf("%d",&a1[i]);
		}
		for(i=1;i<=n;i++)
			scanf("%d",&a2[i]);
		for(i=1;i<n;i++)
			scanf("%d",&h1[i]);
		for(i=1;i<n;i++)
			scanf("%d",&h2[i]);
		printf("Case %d: %d\n",x++,min(rec(1,1),rec(1,2)));
	}
	return 0;
}