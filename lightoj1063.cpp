#include<stdio.h>
#include<vector>
#define si 10010
#define min(a,b) (a<b ?a:b)
using namespace std;
vector<long>ve[si];
long df[si],visit[si],num,cnt,res[si];

long dfs(long node,long p)
{
	visit[node]=1;
	df[node]=num++;
	long l=num,i,ll=ve[node].size(),u,rec;
	for(i=0;i<ll;i++)
	{
		u=ve[node][i];
		if(visit[u]==0&&u!=p)
		{
			visit[u]=1;
			rec=dfs(u,node);
			if(node==1)
				cnt++;
			if(rec>=df[node])
				res[node]++;
			l=min(l,rec);
		}
		else if(u!=p)
			l=min(l,df[u]);
	}
	visit[node]=2;
	return l;
}

int main()
{
	long n,e,u,v,i,c,k=1,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		while(e--)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		num=1;
		cnt=c=0;
		dfs(1,-1);
		for(i=1;i<=n;i++)
		{
			if(res[i]!=0)
			{
				if(i==1&&cnt>1)
					c++;
				else if(i!=1)
					c++;
			}
			ve[i].clear();
			visit[i]=res[i]=0;
		}
		printf("Case %ld: %ld\n",k++,c);
	}
	return 0;
}