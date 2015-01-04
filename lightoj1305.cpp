#include<stdio.h>
#include<math.h>

double cal(long x1,long y1,long x2,long y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double area(double s,double a,double b,double c)
{
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
	long t,ax,ay,bx,by,cx,cy,dx,dy,k=1;
	double a,b,c,d,e,s1,s2,ans1,ans2;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld%ld%ld%ld",&ax,&ay,&bx,&by,&cx,&cy);
		dx=ax+cx-bx;
		dy=ay+cy-by;
		a=cal(ax,ay,cx,cy);
		b=cal(cx,cy,dx,dy);
		c=cal(ax,ay,dx,dy);
		d=cal(ax,ay,bx,by);
		e=cal(bx,by,cx,cy);
		s1=(a+b+c)/2;
		s2=(a+d+e)/2;
		ans1=area(s1,a,b,c);
		ans2=area(s2,a,d,e);
		printf("Case %ld: %ld %ld %.0lf\n",k++,dx,dy,ans1+ans2);
	}
	return 0;
}
