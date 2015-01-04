#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define si 50010
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
using namespace std;
vector<long>ve[si];
queue<long>q;

long cst[si],visit[si],par[si],a[si],res[si];

void bfs(long node)
{
	long i,u,v,l;
	visit[node]=1;
	q.push(node);
	while(!q.empty())
	{
		v=q.front();
		visit[v]=1;
		l=ve[v].size();
		for(i=0;i<l;i++)
		{
			u=ve[v][i];
			if(visit[u]==0)
			{
				visit[u]=1;
				q.push(u);
				cst[u]=cst[v]+1;
				par[u]=v;
			}
		}
		q.pop();
	}
}

int main()
{
	long t,i,n,u,now,j,start,end,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld",&a[1]);
		start=u=a[1];
		par[a[1]]=-1;
		for(i=2;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			ve[u].push_back(a[i]);
			ve[a[i]].push_back(u);
			u=a[i];
			par[a[i]]=-1;
		}
		end=a[n];
		for(i=1;i<=n;i++)
			sort(ve[a[i]].begin(),ve[a[i]].end());
		bfs(start);
		j=1;
		now=end;
		while(now!=start)
		{
			res[j++]=now;
			now=par[now];
		}
		printf("Case %ld:\n",x++);
		printf("%ld",start);
		for(i=j-1;i>=1;i--)
			printf(" %ld",res[i]);
		printf("\n");
		for(i=1;i<=n;i++)
		{
			cst[a[i]]=visit[a[i]]=0;
			ve[a[i]].clear();
		}
	}
	return 0;
}