#include<stdio.h>
#include<vector>
#define si 101
using namespace std;
vector<int>ve[si];

int vis[si][2],cnt;

void dfs(int node,int fg)
{
	int u,i,l;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(vis[u][fg]==0)
		{
			vis[u][fg]=1;
			if(fg==0)
				dfs(u,1);
			else
			{
				cnt++;
				dfs(u,0);
			}
		}
	}
}

int main()
{
	int t,x=1,i,n,e,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		while(e--)
		{
			scanf("%d%d",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		cnt=0;
		dfs(1,0);
		printf("Case %d: %d\n",x++,cnt);
		for(i=1;i<=n;i++)
		{
			ve[i].clear();
			vis[i][0]=vis[i][1]=0;
		}
	}
	return 0;
}