#include<stdio.h>
#include<math.h>
#define max(a,b) (a>b ?a:b)
#define si 1000010

int ara[si],pr[si],ll=1,res[1000100],store[1000100],j;

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

void prime_fact(int nn)
{
	int i,a,cnt,l=sqrt(nn);
	for(i=1;pr[i]<=l;i++)
	{
		if(nn%pr[i]==0)
		{
			cnt=0;
			a=pr[i];
			while(nn%a==0)
			{
				nn/=a;
				cnt++;
			}
			if(res[a]==0)
				store[j++]=a;
			res[a]=max(cnt,res[a]);
			l=sqrt(nn);
		}
	}
	if(nn>1)
	{
		store[j++]=nn;
		res[nn]=max(1,res[nn]);
	}
}

int main()
{
	long long result,lcm,t,n,m,i,cnt,a,l,x=1;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&lcm);
		if((lcm%n)||(lcm%m))
		{
			printf("Case %lld: impossible\n",x++);
			continue;
		}
		j=1;
		prime_fact(n);
		prime_fact(m);
		result=1;
		l=sqrt(lcm);
		for(i=1;pr[i]<=l;i++)
		{
			if(lcm%pr[i]==0)
			{
				cnt=0;
				a=pr[i];
				while(lcm%a==0)
				{
					lcm/=a;
					cnt++;
				}
				if(res[a]!=cnt)
					result*=pow(a,cnt);
				l=sqrt(lcm);
			}
		}
		if(lcm>1)
		{
			if(res[lcm]==0)
				result*=lcm;	
		}
		printf("Case %lld: %lld\n",x++,result);
		for(i=1;i<j;i++)
		{
			a=store[i];
			res[a]=0;
		}
	}
	return 0;
}