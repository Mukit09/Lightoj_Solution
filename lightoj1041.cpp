#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string,long>mp;

long i,j,k=1,t,p[110],r[110],cost,cnt,u,e,v;
char ch1[60],ch2[60];

struct ss
{
	long u,v,cost;
}T[60];

bool cmp(ss aa,ss bb)
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
		p[x]=y,r[y]++;
}

int  main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&e);
		j=1;
		for(i=0;i<e;i++)
		{
			scanf("%s%s%ld",ch1,ch2,&cost);
			if(mp[ch1]==0)
				mp[ch1]=j++;
			if(mp[ch2]==0)
				mp[ch2]=j++;
			T[i].u=mp[ch1];
			T[i].v=mp[ch2];
			T[i].cost=cost;
		}
		sort(T,T+e,cmp);
		for(i=1;i<j;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		cnt=cost=0;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				cost+=T[i].cost;
			}
		}
		for(i=1;i<j;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		if(cnt==1)
			printf("Case %ld: %ld\n",k++,cost);
		else
			printf("Case %ld: Impossible\n",k++);
		mp.clear();
	}
	return 0;
}