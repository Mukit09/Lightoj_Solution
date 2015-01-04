#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,d,e,f;
	long t,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		e=4*fabs(a-c);
		e=(c+a)/e;
		f=e*sqrt((-c+a+d+b)*(c-a+d+b)*(c-a+d-b)*(c-a-d+b));
		printf("Case %ld: %lf\n",k++,f);
	}
	return 0;
}