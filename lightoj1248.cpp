#include<stdio.h>
#include<math.h>

int main()
{
	int i,t,x=1;
	double ans,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		ans=1;
		for(i=1;i<n;i++)
			ans+=(n/(n-i));
		printf("Case %d: %lf\n",x++,ans);
	}
	return 0;
}