#include<stdio.h>
#include<math.h>
#define si 40000
long long mod =1000000007;

bool ara[si];
int pr[si],ll=1;

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	ara[0]=ara[1]=1;
	pr[ll++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}

long long bmod(long long a,long long b)
{
	if(b==0)
		return 1;
	long long x=bmod(a,b/2);
	x=(x*x)%mod;
	if(b%2==1)
		x=(x*(a%mod))%mod;
	return x;
}

int main()
{
	sieve();
	long long t,n,m,x=1,sm,l,p,cnt,i,in_mod,md;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		l=sqrt(n);
		sm=1;
		for(i=1;pr[i]<=l&&i<ll;i++)
		{
			if(n%pr[i]==0)
			{
				cnt=0;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					cnt++;
				}
				l=sqrt(n);
				md=bmod(pr[i],cnt*m+1);
				sm=((sm%mod)*(md-1))%mod;
				in_mod=bmod(pr[i]-1,mod-2);
				sm=((sm%mod)*(in_mod%mod))%mod;
			}
		}
		if(n>1)
		{
			md=bmod(n,m+1);
			sm=((sm%mod)*(md-1))%mod;
			in_mod=bmod(n-1,mod-2);
			sm=((sm%mod)*(in_mod%mod))%mod;
		}
		if(sm<0)
			sm+=mod;
		printf("Case %lld: %lld\n",x++,sm);

	}
	return 0;
}
