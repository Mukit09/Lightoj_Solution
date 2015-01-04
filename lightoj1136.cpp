#include<stdio.h>
#include<math.h>

int main()
{
	long k=1,t,a,b,c;
	double e,d;
	
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		c=0;
		if(a%3==2)
			a--;
		else if(a%3==0)
		{
			a++;
			c=1;
		}
		if(b%3==0)
			b++;
		d=b-a;
		d=2*d;
		e=ceil(d/3)+c;
		printf("Case %ld: %.0lf\n",k++,e);
	}
	return 0;
}
		