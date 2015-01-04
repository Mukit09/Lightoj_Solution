#include<stdio.h>
#include<math.h>
#define si 2000010
#define mod 1000000007
typedef long long i64;

i64 fact[si];

i64 bmod(i64 a,i64 b)
{
	if(b==0)
		return 1;
	i64 x=bmod(a,b>>1);
	x=(x*x)%mod;
	if(b%2)
		x=(x*a)%mod;
	return x;
}

int main()
{
	i64 i,ans;
	fact[0]=fact[1]=1;
	for(i=2;i<=si-10;i++)
		fact[i]=(fact[i-1]*i)%mod;

	int t,n,m,x=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=(fact[n]*fact[m-1])%mod;
		ans=(fact[n+m-1]*bmod(ans,mod-2))%mod;
		printf("Case %d: %lld\n",x++,ans);
	}
	return 0;
}