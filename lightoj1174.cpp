#include<stdio.h>

int main()
{
	long a[101][101],n,e,u,v,i,j,k,t,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
					a[i][j]=99999999;
				else
					a[i][j]=0;
			}
		}
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			a[u][v]=a[v][u]=1;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
		scanf("%ld%ld",&u,&v);
		printf("Case %ld: %ld\n",x++,a[u][v]);
	}
	return 0;
}