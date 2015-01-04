#include<stdio.h>
#include<math.h>
#define si 1000006

long long mod=1000003,fact[si],mod_inv[si];

long long bmod(long long a,long long b)
{
	if(b==0)
		return 1;
	long long x=bmod(a,b/2);
	x=(x*x)%mod;
	if(b%2==1)
		x=(x*a)%mod;
	return x;
}

int main()
{
	int t,x=1,ans,i,n,k;
	fact[0]=mod_inv[0]=1;

	for(i=1;i<=si-5;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		mod_inv[i]=(mod_inv[i-1]*bmod(i,mod-2))%mod;
	}

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		ans=fact[n];
		ans=(ans*mod_inv[k])%mod;
		ans=(ans*mod_inv[n-k])%mod;
		printf("Case %d: %d\n",x++,ans);
	}
	return 0;
}