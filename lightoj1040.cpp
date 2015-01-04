#include<stdio.h>
#include<algorithm>
using namespace std;

long p[110],r[110],i,j,k=1,t,n,u,v,cost,cnt,ll;

struct ss
{
	long u,v,cost;
}T[10100];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

long find(long x)
{
	if(x==p[x]) return x;
	else return p[x]=find(p[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		ll=0;
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			for(j=1;j<=n;j++)
			{
				scanf("%ld",&cost);
				if(cost)
				{
					T[ll].u=i;
					T[ll].v=j;
					T[ll++].cost=cost;
				}
			}
		}
		sort(T,T+ll,cmp);
		cost=0;
		for(i=0;i<ll;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
				link(u,v);
			else
				cost+=T[i].cost;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		if(cnt==1)
			printf("Case %ld: %ld\n",k++,cost);
		else
			printf("Case %ld: -1\n",k++);
	}
	return 0;
}