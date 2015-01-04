#include<stdio.h>
#include<math.h>
#define pi 3.1415926535

double x=1,t,n,deg,R,r;

int main()
{
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf%lf",&R,&n);
		deg=360/(n*2);
		deg=(deg*pi)/180;
		deg=sin(deg);
		r=(deg*R)/(deg+1);
		printf("Case %.0lf: %lf\n",x++,r);
	}
	return 0;
}
