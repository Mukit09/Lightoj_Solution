#include<stdio.h>
#include<string.h>
#define si 1010
#define mod 1000007
#define max(a,b) (a>b ?a:b)
char ch1[si],ch2[si];
long l1,l2,dp[si][si],w[si][si];

long rec(long i1,long i2)
{
	if(i1==l1||i2==l2)
		return 0;
	
	if(dp[i1][i2]!=-1)
		return dp[i1][i2];

	long p1;
	if(ch1[i1]==ch2[i2])
		p1=rec(i1+1,i2+1)+1;
	else
		p1=max(rec(i1+1,i2),rec(i1,i2+1));
	return dp[i1][i2]=p1;
}

long way(long i1,long i2)
{
	if(i1==l1||i2==l2)
		return 1;
	if(w[i1][i2]!=-1)
		return w[i1][i2];
	long p=0;
	if(ch1[i1]==ch2[i2])
		p=way(i1+1,i2+1);
	else
	{
		if(rec(i1,i2)==rec(i1+1,i2))
			p=(p+way(i1+1,i2))%mod;
		if(rec(i1,i2)==rec(i1,i2+1))
			p=(p+way(i1,i2+1))%mod;
		if(rec(i1,i2)==rec(i1+1,i2+1))
			p=(p-way(i1+1,i2+1)+mod)%mod;
	}
	return w[i1][i2]=p%mod;
}

int main()
{
	long x=1,i,j,t,cnt;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch1);
		gets(ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		for(i=0;i<l1;i++)
		{
			for(j=0;j<l2;j++)
				dp[i][j]=w[i][j]=-1;
		}
		rec(0,0);
		cnt=way(0,0);
		printf("Case %ld: %ld\n",x++,cnt);
	}
	return 0;
}
