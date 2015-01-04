#include<stdio.h>

int main()
{
	long n,i,t,k=1,c,now;
	long a[15];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld",&a[1]);
		c=0;
		if(a[1]>2)
		{
			now=a[1]-2;
			while(1)
			{
				c=c+now/5;
				if(now%5==0)
					break;
				else
				{
					c++;
					break;
				}
			}
		}
		for(i=2;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]>a[i-1])
			{
				now=a[i]-a[i-1];
				while(1)
				{
					c=c+now/5;
					if(now%5==0)
						break;
					else
					{
						c++;
						break;
					}
				}
			}
		}
		printf("Case %ld: %ld\n",k++,c);
	}
	return 0;
}