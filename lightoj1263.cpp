#include<stdio.h>
#include<vector>
#define si 1010
using namespace std;
vector<long>ve[si];

long a[si],visit[si],sm,av,key;

void dfs(long node)
{
	visit[node]=1;
	long i,u,l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			key+=(av-a[u]);
			visit[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long t,k=1,i,n,e,fg,u,v;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			sm+=a[i];
		}
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		av=sm/n;
		if(av*n==sm)
		{
			fg=1;
			key=av-a[1];
			dfs(1);
			if(key==0)
				printf("Case %ld: Yes\n",k++);
			else
				printf("Case %ld: No\n",k++);
		}
		else
			printf("Case %ld: No\n",k++);
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			ve[i].clear();
		}
	}
	return 0;
}