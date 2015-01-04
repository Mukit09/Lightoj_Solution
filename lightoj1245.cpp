#include<stdio.h>
#include<math.h>

long long H(long n)
{
	long long lq,sum,pq,i,l;
	l=sqrt(n);
	sum=0;
	for(i=1;i<=l;i++) 
	{
        lq=n/i;
		pq=n/(i+1);
		if(pq>=l)
			sum=sum+(lq-pq)*i+lq;
		else
			sum+=lq;
	}
    return sum;
}

int main()
{
	long i,t,n;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&n);
		if(n<=0)
		{
			printf("0\n");
			continue;
		}
		printf("Case %ld: %lld\n",i,H(n));
	}
	return 0;
}
