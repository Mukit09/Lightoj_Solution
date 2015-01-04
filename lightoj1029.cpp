#include<stdio.h>
#include<algorithm>
using namespace std;

long p[110],p1[110],r[110],r1[110],i,j,k=1,t,re,n,u,v,a,b;
struct ss
{
	long u,v,cost;
}T[12010];

bool cmp(ss aa, ss bb)
{
	return aa.cost<bb.cost;
}

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

long find1(long x)
{
	if(p1[x]==x)
		return x;
	else return p1[x]=find1(p1[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

void link1(long x,long y)
{
	if(r1[x]>=r1[y])
		p1[y]=x,r1[x]++;
	else
		p1[x]=y,r1[y]++;
}

int main()
{
	long max,min;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			p1[i]=i;
			r1[i]=1;
		}
		i=0;
		while(scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost)&&(T[i].u||T[i].v||T[i].cost))
		{
			i++;
		}
		sort(T,T+i,cmp);
		j=i;
		min=max=0;
		for(i=0,a=j-1;i<j;i++,a--)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				min+=T[i].cost;
				link(u,v);
			}
			u=find1(T[a].u);
			v=find1(T[a].v);
			if(u!=v)
			{
				max+=T[a].cost;
				link1(u,v);
			}
		}
		re=max+min;
		if(re%2==0)
			printf("Case %ld: %ld\n",k++,re/2);
		else
			printf("Case %ld: %ld/2\n",k++,re);
	}
	return 0;
}