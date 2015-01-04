#include<stdio.h>
#define si 110

long a[si],i,j,cnt,t,n,x=1,chk[si];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			chk[a[i]]=i;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=i)
			{
				j=chk[i];
				a[j]=a[i];
				chk[a[i]]=j;
				a[i]=i;		
				cnt++;

			}
		}
		printf("Case %ld: %ld\n",x++,cnt);
	}
	return 0;
}