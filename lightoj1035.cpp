#include<stdio.h>
long pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
long a[110];

int main()
{
	long t,i,n,m,j,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=2;i<=n;i++)
		{
			m=i;
			for(j=0;pr[j]<=i;j++)
			{
				if(m%pr[j]==0)
				{
					while(m%pr[j]==0)
					{
						a[pr[j]]++;
						m/=pr[j];
					}
				}
			}
		}
		printf("Case %ld: %ld =",x++,n);
		for(i=2;i<=n;i++)
		{
			if(a[i])
			{
				if(i==2)
					printf(" %ld (%ld)",i,a[i]);
				else
					printf(" * %ld (%ld)",i,a[i]);
			}
			a[i]=0;
		}
		printf("\n");
	}
	return 0;
}
					