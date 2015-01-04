#include<stdio.h>
#include<math.h>
#define pi 3.1415926535

int main()
{
	double oa,ob,ab,ox,oy,ax,ay,bx,by,ans,t,k=1;
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
		oa=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
		ob=sqrt((ox-bx)*(ox-bx)+(oy-by)*(oy-by));
		ab=sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
		ans=acos((oa*oa+ob*ob-ab*ab)/(2*oa*ob));
		ans=ans=ans*oa;
		printf("Case %.0lf: %lf\n",k++,ans);
	}
	return 0;
}
