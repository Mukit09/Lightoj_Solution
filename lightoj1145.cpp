#include<stdio.h>
#include<math.h>
#define mod 100000007
int dp[2][15001];

int main()
{
	int n,s,k,i,j,x=1,t,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&s);
		for(i=0;i<=s;i++)
			dp[0][i]=dp[1][i]=0;
		dp[0][0]=1;
		for(i=1;i<=n;i++)
		{
			z=i%2;
			for(j=0;j<=s;j++)
				dp[z][j]=0;
			for(j=1;j<=s;j++)
			{
				dp[z][j]=(dp[1-z][j-1]+dp[z][j-1])%mod;
				if(j-k-1>=0)
					dp[z][j]=(dp[z][j]-dp[1-z][j-k-1]+mod)%mod;
			}
		}
		printf("Case %d: %d\n",x++,dp[n%2][s]);
	}
	return 0;
}