#include<stdio.h>
#include<vector>
#include<algorithm>
#define si 510
using namespace std;

vector<long>adj[si];
long t,x=1,j,k,r[si],p[si],cost,n,e,d[si],visit[si],w[si][si];

struct ss
{
	long u,v,cost;
}T[16010];

bool cmp(ss aa, ss bb)
{
	return aa.cost<bb.cost;
}

long find(long x)
{
	if(x==p[x])
		return x;
	else return p[x]=find(p[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y;r[y]++;
}

void dfs(long node,long mx)
{
	long i,u;
	visit[node]=1;
	for(i=0;i<adj[node].size();i++)
	{
		u=adj[node][i];
		if(visit[u]==0)
		{
			if(w[node][u]>mx)
				mx=d[u]=w[node][u];
			else
				d[u]=mx;
			dfs(u,mx);
		}
	}
}

int main()
{
	long u,v,i;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=0;i<n;i++)
		{
			r[i]=1;
			p[i]=i;
			visit[i]=0;
		}
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
	
		sort(T,T+e,cmp);
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				u=T[i].u;
				v=T[i].v;
				adj[u].push_back(v);
				adj[v].push_back(u);
				w[u][v]=w[v][u]=T[i].cost;
			}
		}
		scanf("%ld",&u);
		d[u]=0;
		dfs(u,0);
		printf("Case %ld:\n",x++);
		for(i=0;i<n;i++)
		{
			if(visit[i])
				printf("%ld\n",d[i]);
			else
				printf("Impossible\n");
			adj[i
				].clear();
		}
	}
	return 0;
}
