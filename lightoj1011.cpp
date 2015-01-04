#include<stdio.h>
#include<math.h>
#define si 16
#define max(a,b) (a>b?a:b)

int a[si][si],n,dp[si][1<<si];

int rec(int i,int mask)
{
	if(i==n)
		return 0;
	int j,&r=dp[i][mask],cst;
	if(r!=-1)
		return r;
	r=-1;
	for(j=0;j<n;j++)
	{
		if((mask&(1<<j))==0)
		{
			cst=rec(i+1,mask|(1<<j))+a[i][j];
			if(cst>r)
				r=cst;
		}
	}
	return r;
}

int main()
{
	int t,x=1,max_s,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max_s=1<<n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			for(j=0;j<max_s;j++)
				dp[i][j]=-1;
		}
		printf("Case %d: %d\n",x++,rec(0,0));
	}
	return 0;
}