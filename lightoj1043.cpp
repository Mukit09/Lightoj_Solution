#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,re,p;
	long t,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&p);
		re=sqrt(1+1/p);
		re=a/re;
		printf("Case %ld: %lf\n",k++,re);
	}
	return 0;
}