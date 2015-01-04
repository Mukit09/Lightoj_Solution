#include<stdio.h>
#include<algorithm>
#define si 201
#define inf 1<<29
using namespace std;

int r[si],p[si],a=1,t,u,v,n,e,cst,cnt,l,k,cost,x,y,visit[si];

struct ss
{
	int u,v,cost;
}T[6005];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

int find(int x)
{
	if(x==p[x])
		return x;
	else 
		return p[x]=find(p[x]);
}

void link(int x,int y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

void make_set()
{
	int i;
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		r[i]=1;
	}
}

int main()
{
	int i,j,ind,sm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		k=sm=0;
		printf("Case %d:\n",a++);
		for(i=1;i<=n;i++)
			visit[i]=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d",&u,&v,&cost);
			T[k].u=u;
			T[k].v=v;
			T[k].cost=cost;
			k++;
			if(visit[u]==0)
				visit[u]=1,sm++;
			if(visit[v]==0)
				visit[v]=1,sm++;
			if(sm>=n)
			{
				make_set();
				sort(T,T+k,cmp);
				
				cst=cnt=0;
				for(j=0;j<k;j++)
				{
					u=find(T[j].u);
					v=find(T[j].v);
					if(u!=v)
					{
						link(u,v);
						cst+=T[j].cost;
						ind=j;
					}
					else
					{
						u=T[j].u;
						v=T[j].v;
						T[j].cost=inf;
					}
				}
				for(j=1;j<=n;j++)
				{
					u=find(j);
					if(u==j)
						cnt++;
				}
				if(cnt==1)
				{
					printf("%d\n",cst);
					k=ind+1;
				}
				else
					printf("-1\n");
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}