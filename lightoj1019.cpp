#include<stdio.h>

int main()
{
	long a[101][101],i,j,k,n,e,u,v,w,t,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j)
					a[i][j]=999999999;
				else
					a[i][j]=0;
			}
		}
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld%ld",&u,&v,&w);
			if(a[u][v]>w)
			{
				a[u][v]=a[v][u]=w;
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}
		if(a[1][n]>=999999999)
		{
			printf("Case %ld: Impossible\n",x++);
			continue;
		}
		printf("Case %ld: %ld\n",x++,a[1][n]);
	}
	return 0;
}
