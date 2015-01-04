#include<stdio.h>

int main()
{
	double v1,v2,v3,a1,a2,d,s,t1,t2;
	long t,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
		
		d=(v1*v1)/(2*a1)+(v2*v2)/(2*a2);

		t1=v1/a1;
		t2=v2/a2;
		
		if(t1<t2)
			s=v3*t2;
		else
			s=v3*t1;

		printf("Case %ld: %lf %lf\n",k++,d,s);
	}
	return 0;
}