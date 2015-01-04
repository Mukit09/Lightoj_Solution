#include<stdio.h>

int main()
{
	long t,k=1,n,d,c,e;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&d);
		c=0;
		e=d;
		while(1)
		{
			c++;
			if(d==0||d%n==0)
			{
				break;
			}
			d=d*10+e;
			d=d%n;
		}
		printf("Case %ld: %ld\n",k++,c);
	}
	return 0;
}
