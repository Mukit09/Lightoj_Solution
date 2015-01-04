#include<stdio.h>
#include<vector>
#define si 30010
#define max(a,b) (a<b?b:a)
using namespace std;

vector<long>ve[si],ve_w[si];
long visit[si],visit1[si],cst[si],cst1[si],n,mx,ii,t,w,x=1;

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

void dfs1(long node)
{
	visit1[node]=1;
	long i,u,l,ww;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit1[u]==0)
		{
			visit1[u]=1;
			ww=ve_w[node][i];
			cst1[u]=cst1[node]+ww;
			dfs1(u);
		}
	}
}

int main()
{
	long i,u,v;
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
			visit[i]=cst[i]=0;
		}
		visit[i]=cst[i]=0;
		mx=0;
		dfs(0);
		for(i=0;i<n;i++)
			visit[i]=cst[i]=visit1[i]=cst1[i]=0;
		mx=0;
		dfs(ii);
		mx=0;
		dfs1(ii);
		printf("Case %ld:\n",x++);
		for(i=0;i<n;i++)
		{
			printf("%ld\n",max(cst1[i],cst[i]));
			ve_w[i].clear();
			ve[i].clear();
		}
	}
	return 0;
}