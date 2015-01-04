#include<stdio.h>
#include<string.h>
#define inf 9999999
#define min(a,b) (a<b ?a:b)
char ch[1010];
long l,x=1,dp[1010];

long pal(long i,long j)
{
	long x,y;
	for(x=i,y=j;x<=j;x++,y--)
	{
		if(ch[x]!=ch[y])
			return 0;
	}
	return 1;
}

long rec(long ind)
{
	if(ind==l)
		return 0;
	if(dp[ind]!=-1)
		return dp[ind];
	long i,mn=inf;
	for(i=ind;i<l;i++)
	{
		if(pal(ind,i))
			mn=min(mn,rec(i+1)+1);
	}
	return dp[ind]=mn;
}

int main()
{
	long t,i,res;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0;i<l;i++)
			dp[i]=-1;
		res=rec(0);
		printf("Case %ld: %ld\n",x++,res);
	}
	return 0;
}