#include<stdio.h>
#include<vector>
#include<queue>
#define min(a,b) (a<b ?a:b)
#define si 10010
using namespace std;
vector<long>ve[10010];
queue<long>q;

long visit[si],in[si];

void dfs(long node)
{
	long i,u;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long t,i,k=1,l,cnt,u,v,n,e,fg,x,mn;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			in[v]++;
		}
		fg=0;
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				fg=1;
				q.push(i);
			}
		}
		cnt=0;
		while(q.empty()==0)
		{
			x=q.front();
			if(visit[x]==0)
			{
				cnt++;
				dfs(x);
			}
			q.pop();
		}
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				cnt++;
				dfs(i);
			}
		}
		mn=cnt;
		cnt=0;
		for(i=n;i>=1;i--)
		{
			visit[i]=0;
			if(in[i]==0)
				q.push(i);
		}

		for(i=n;i>=1;i--)
		{
			if(visit[i]==0)
			{
				cnt++;
				dfs(i);
			}
		}
		while(q.empty()==0)
		{
			x=q.front();
			if(visit[x]==0)
			{
				cnt++;
				dfs(x);
			}
			q.pop();
		}
		mn=min(mn,cnt);
		printf("Case %ld: %ld\n",k++,mn);
		for(i=1;i<=n;i++)
		{
			in[i]=visit[i]=0;
			ve[i].clear();
		}
	}
	return 0;
}