#include<stdio.h>
#include<math.h>
int main()
{
	long n,p,q,a,b,c,m,t,k=1;
	double d,ck;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		d=sqrt(n);
		a=(long)d;
		ck=d-a;
		if(ck>0)
			a++;
		b=(a-1)*(a-1);
		b=n-b;
		m=(2*a)-1;
		c=(m/2)+1;
		if(a%2==0)
		{
			if(b==c)
			{
				p=a;
				q=a;
			}
			else if(b>c)
			{
				p=a;
				q=(2*a)-b;
			}
			else if(b<c)
			{
				p=b;
				q=a;
			}
		}
		else
		{
			if(b==c)
			{
				p=a;
				q=a;
			}
			else if(b>c)
			{
				p=(2*a)-b;
				q=a;
			}
			else if(b<c)
			{
				p=a;
				q=b;
			}
		}
		printf("Case %ld: %ld %ld\n",k++,p,q);
	}
	return 0;
}