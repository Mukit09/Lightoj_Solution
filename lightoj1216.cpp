#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

int main()
{
	long double r1,r2,h,p,r,vol;
	long t,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%llf%llf%llf%llf",&r1,&r2,&h,&p);
		r=(((r1-r2)*p)/h)+r2;
		vol=(pi*p*(r*r+r*r2+r2*r2))/3;
		printf("Case %ld: %.09llf\n",k++,vol);
	}
	return 0;
}