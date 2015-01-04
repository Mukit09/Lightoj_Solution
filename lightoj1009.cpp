#include<stdio.h>
#include<vector>
#include<map>
#define si 100100
using namespace std;
vector<long>ve[si];
map<long,long>mp;

long a[si],visit[si],x=1,cnt1,cnt2,mx;

long max(long aa,long bb)
{
	if(aa>bb) return aa;
	return bb;
}

void dfs(long node)
{
	long i,v;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		v=ve[node][i];
		if(visit[v]==0)
		{
			if(a[node]==1)
			{
				cnt2++;
				a[v]=2;
			}
			else
			{
				cnt1++;
				a[v]=1;
			}
			mx=max(cnt1,cnt2);
			visit[v]=1;
			dfs(v);
		}
	}
}

int main()
{
	long i,j,t,n,u,v,sm;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=j=1;i<=n;i++)
		{
			scanf("%ld%ld",&u,&v);
			if(mp[u]==0)
			{
				mp[u]=j;
				visit[j]=0;
				a[j++]=0;
			}
			if(mp[v]==0)
			{
				mp[v]=j;
				visit[j]=0;
				a[j++]=0;
			}
			ve[mp[u]].push_back(mp[v]);
			ve[mp[v]].push_back(mp[u]);
		}
		sm=0;
		for(i=1;i<j;i++)
		{
			if(visit[i]==0)
			{
				cnt1=1,cnt2=0;
				a[i]=1;
				dfs(i);
				sm+=mx;
			}
		}
		for(i=1;i<j;i++)
			ve[i].clear();
		printf("Case %ld: %ld\n",x++,sm);
		mp.clear();
	}
	return 0;
}
