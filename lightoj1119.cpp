#include<stdio.h>
#include<math.h>
#define si 15
#define inf 99999999
#define min(a,b) (a<b?a:b)
int dp[1<<si],a[si][si],n,max_s;

int rec(int mask)
{
	if(mask==max_s)
		return 0;
	int &ret=dp[mask];
	if(ret!=-1)
		return ret;
	int mn=inf,i,j,cst;
	for(i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			int price=a[i][i];
			for(j=0;j<n;j++)
			{
				if(i!=j&&(mask&(1<<j))!=0)
					price+=a[i][j];
			}
			cst=price+rec(mask|(1<<i));
			if(cst<mn)
				mn=cst;
		}
	}
	return ret=mn;
}

int main()
{
	int t,i,j,x=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		}
		max_s=1<<n;
		for(i=0;i<max_s;i++)
			dp[i]=-1;
		max_s--;
		printf("Case %d: %d\n",x++,rec(0));
	}
	return 0;
}