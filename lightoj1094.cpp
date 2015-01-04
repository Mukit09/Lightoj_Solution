#include<stdio.h>
#include<vector>
#define si 30010
using namespace std;

vector<long>ve[si],ve_w[si];
long visit[si],cst[si],n,mx,ii,t,w,x=1;

void dfs(long node)
{
	visit[node]=1;
	long i,u,l,ww;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			ww=ve_w[node][i];
			cst[u]=cst[node]+ww;
			if(mx<cst[u])
			{
				mx=cst[u];
				ii=u;
			}
			dfs(u);
		}
	}
}

int main()
{
	long i,u,v,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n-1;i++)
		{
			scanf("%ld%ld%ld",&u,&v,&w);
			ve[u].push_back(v);
			ve[v].push_back(u);
			ve_w[u].push_back(w);
			ve_w[v].push_back(w);
			visit[i]=0;
		}
		visit[i]=0;
		mx=0;
		dfs(0);
		j=ii;
		for(i=0;i<n;i++)
			visit[i]=cst[i]=0;
		mx=0;
		dfs(ii);
		printf("Case %ld: %ld\n",x++,cst[ii]);
		for(i=0;i<n;i++)
		{
			ve_w[i].clear();
			ve[i].clear();
		}
	}
	return 0;
}