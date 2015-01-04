#include<stdio.h>

int main()
{
	long n,m,t,k=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		printf("Case %ld: %ld\n",k++,(n*m)/2);
	}
	return 0;
}