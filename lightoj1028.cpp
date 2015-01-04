#include<stdio.h>
#include<math.h>
#define si 1000010

int ara[si],pr[si],ll=1;

void sieve()
{
	long long num=si-5,i,j,root;
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

int main()
{
	long long i,n,j,t,cnt,l,res,x=1;
	sieve();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		l=sqrt(n)+1;
		res=1;
		for(i=1;pr[i]<=l;i++)
		{
			if(n%pr[i]==0)
			{
				cnt=0;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					cnt++;
				}
				res*=(cnt+1);
				l=sqrt(n);
			}
		}
		if(n>1)
			res*=2;
		printf("Case %lld: %lld\n",x++,res-1);
	}
	return 0;
}
