#include<stdio.h>
#include<math.h>
#define si 1001
#define mod 10056

int fact[si],s[si][si];

int main()
{
	int i,t,j,x=1,n,ans;
	fact[0]=1;
	for(i=1;i<si;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		s[i][i]=s[i][1]=1;
	}
	for(i=2;i<si;i++)
	{
		for(j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
			ans=(ans+(s[n][i]*fact[i]))%mod;
		printf("Case %d: %d\n",x++,ans);
	}
	return 0;
}