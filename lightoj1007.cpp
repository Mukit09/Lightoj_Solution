#include<stdio.h>
#include<math.h>
#define si 5000010
bool ara[si];
unsigned long long phi[si],m;

void sieve()
{
	long num=si-5,i,j,root,fg=1;
	for(i=2;i<=num;i++)
	{
		phi[i]=i;
		if(fg)
		{
			fg=0;
			phi[i]/=2;
		}
		else
			fg=1;
	}

	root=sqrt(num);
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;			
			}
			for(j=i;j<num;j+=i)
			{
				phi[j]*=(i-1);
				phi[j]/=i;
			}
		}
    }
	for(i=2;i<num;i++)
		phi[i]=phi[i-1]+phi[i]*phi[i];
}

int main()
{
	sieve();
	unsigned long long t,i,u,v,k=1,sm;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%llu%llu",&u,&v);
		printf("Case %ld: %llu\n",k++,phi[v]-phi[u-1]);
	}
	return 0;
}