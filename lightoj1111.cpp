#include<stdio.h>
#include<vector>
#define si 1010
using namespace std;
vector<long>ve[si];

long visit[si],a[110],cnt[si];

void dfs(long node)
{
	long i,u,l;
	visit[node]=1;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			cnt[u]++;
			visit[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long t,n,k,x=1,e,i,j,u,v,res;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&k,&n,&e);
		for(i=1;i<=k;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
		}
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=n;j++)
				visit[j]=0;
			cnt[a[i]]++;
			dfs(a[i]);
		}
		res=0;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]==k)
				res++;
			ve[i].clear();
			cnt[i]=0;
			visit[i]=0;
		}
		printf("Case %ld: %ld\n",x++,res);
	}
	return 0;
}