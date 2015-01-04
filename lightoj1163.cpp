#include<stdio.h>
#include<math.h>

int main()
{
	int t,x=1;
	long long n,ans,chk;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=n+n/9;
		printf("Case %d:",x++);
		if(n%9==0)
			printf(" %lld",ans-1);
		printf(" %lld\n",ans);
	}
	return 0;
}

