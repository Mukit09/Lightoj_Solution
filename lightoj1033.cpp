#include<stdio.h>
#include<string.h>

char st1[110],st2[110];
long l1,dp[110][110],x=1;

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

long rec(long i,long j)
{
	if(i<0||j<0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(st1[i]==st2[j])
		dp[i][j]=rec(i-1,j-1)+1;
	else 
	{
		long p1,p2;
		p1=rec(i-1,j);
		p2=rec(i,j-1);
		dp[i][j]=max(p1,p2);
	}
	return dp[i][j];
}

int main()
{
	long i,j,k,ans,t;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(st1);
		l1=strlen(st1);
		k=l1-1;
		for(i=0,k=l1-1;i<l1;i++,k--)
		{
			for(j=0;j<l1;j++)
				dp[i][j]=-1;
			st2[i]=st1[k];
		}
		st2[i]=0;
		ans=rec(l1-1,l1-1);
		printf("Case %ld: %ld\n",x++,l1-ans);
	}
	return 0;
}