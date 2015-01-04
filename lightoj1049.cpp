#include<stdio.h>
#define si 110
#define inf 999999
#define min(a,b) (a<b ?a:b)

long visit[si],a[si][si],mat[si][si],cst,cst_rev,mn,n;

void dfs(int node,int p)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(visit[i]==0&&(mat[node][i]==1||mat[i][node]==1)&&i!=p)
		{
			visit[i]=1;
			if(mat[node][i]==1)
				cst+=a[node][i];
			else if(mat[i][node]==1)
				cst_rev+=a[i][node];
			dfs(i,node);
		}
	}
}

int main()
{
	int x=1,t,u,v,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&u,&v,&cst);
			mat[u][v]=1;
			a[u][v]=cst;
		}
		cst=cst_rev=0;
		dfs(1,-1);
		printf("Case %d: %d\n",x++,min(cst,cst_rev));
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			for(j=1;j<=n;j++)
				mat[i][j]=0;
		}
	}
	return 0;
}