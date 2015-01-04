#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 30
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int i,j,l,n,m,cnt,sm,fg,visa[si][si],visb[si][si],visc[si][si],cost[si][si],x,y,cs=1;
char ch[si][si];
queue<int>q;

/*
i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}*/

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

/*
i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}
*/

void bfsa(int u,int v)
{
	int i,nwx,nwy;
	q.push(u);
	q.push(v);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&ch[nwx][nwy]!='m'&&ch[nwx][nwy]!='#'&&visa[nwx][nwy]==0)
			{
				visa[nwx][nwy]=1;
				cost[nwx][nwy]=cost[u][v]+1;
				if(nwx==x&&nwy==y)
				{
					while(!q.empty())
						q.pop();
					break;
				}
				q.push(nwx);
				q.push(nwy);
			}
		}
	}
}

void bfsb(int u,int v)
{
	int i,nwx,nwy;
	q.push(u);
	q.push(v);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&ch[nwx][nwy]!='m'&&ch[nwx][nwy]!='#'&&visb[nwx][nwy]==0)
			{
				visb[nwx][nwy]=1;
				cost[nwx][nwy]=cost[u][v]+1;
				if(nwx==x&&nwy==y)
				{
					while(!q.empty())
						q.pop();
					break;
				}
				q.push(nwx);
				q.push(nwy);
			}
		}
	}
}

void bfsc(int u,int v)
{
	int i,nwx,nwy;
	q.push(u);
	q.push(v);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&ch[nwx][nwy]!='m'&&ch[nwx][nwy]!='#'&&visc[nwx][nwy]==0)
			{
				visc[nwx][nwy]=1;
				cost[nwx][nwy]=cost[u][v]+1;
				if(nwx==x&&nwy==y)
				{
					while(!q.empty())
						q.pop();
					break;
				}
				q.push(nwx);
				q.push(nwy);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t,mx;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d",&n,&m);
		rep(i,0,n)
			scanf("%s",ch[i]);
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if(ch[i][j]=='h')
					x=i,y=j;
				visa[i][j]=visb[i][j]=visc[i][j]=0;
			}
		}
		mx=-1;
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if(ch[i][j]=='a')
				{
					cost[i][j]=0;
					bfsa(i,j);
					mx=max(cost[x][y],mx);
				}
				else if(ch[i][j]=='b')
				{
					cost[i][j]=0;
					bfsb(i,j);
					mx=max(cost[x][y],mx);
				}
				else if(ch[i][j]=='c')
				{
					cost[i][j]=0;
					bfsc(i,j);
					mx=max(cost[x][y],mx);
				}
			}
		}
		printf("Case %d: %d\n",cs++,mx);
    }
   	return 0;
}
