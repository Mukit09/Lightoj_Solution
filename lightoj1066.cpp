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
#define si 15
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
int i,j,l,n,x,y,cnt,sm,fg,vis[si][si],vis_nxt[si][si],cst[si][si],mx,mxx,mxy,cs=1,capx[30],capy[30],nw;
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

void bfs(int u,int v)
{
	ch[u][v]='.';
	vis[u][v]=1;
	int i,nwx,nwy;
	q.push(u);
	q.push(v);
	q.push(cnt);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		cnt=q.front();
		q.pop();
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<n&&nwy>=0&&ch[nwx][nwy]=='.'&&vis[nwx][nwy]==0)
			{
				vis[nwx][nwy]=1;
				cst[nwx][nwy]=cst[u][v]+1;
				q.push(nwx);
				q.push(nwy);
				q.push(cnt);
			}
			else if(nwx<n&&nwx>=0&&nwy<n&&nwy>=0&&ch[nwx][nwy]!='#'&&vis[nwx][nwy]==0&&(cnt+1)==ch[nwx][nwy])
			{
				vis[nwx][nwy]=1;
				ch[nwx][nwy]='.';
				cst[nwx][nwy]=cst[u][v]+1;
				if(cnt==mx)
				{
					while(!q.empty())
						q.pop();
					break;
				}
				q.push(nwx);
				q.push(nwy);
				q.push(cnt+1);
				nw=cnt+1;
			}
		}
	}
}

void bfs_nxt(int u,int v)
{
	vis_nxt[u][v]=1;
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
			if(nwx<n&&nwx>=0&&nwy<n&&nwy>=0&&ch[nwx][nwy]=='.'&&vis_nxt[nwx][nwy]==0)
			{
				vis_nxt[nwx][nwy]=1;
				cst[nwx][nwy]=cst[u][v]+1;
				q.push(nwx);
				q.push(nwy);
			}
			else if(nwx<n&&nwx>=0&&nwy<n&&nwy>=0&&ch[nwx][nwy]!='#'&&vis_nxt[nwx][nwy]==0&&(cnt+1)==ch[nwx][nwy])
			{
				nw=cnt+1;
				vis_nxt[nwx][nwy]=1;
				ch[nwx][nwy]='.';
				cst[nwx][nwy]=cst[u][v]+1;
				while(!q.empty())
					q.pop();
				break;
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d",&n);
		rep(i,0,n)
			scanf("%s",&ch[i]);
		mx=-1;
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				if(ch[i][j]>=65&&ch[i][j]<=90)
					capx[ch[i][j]-64]=i,capy[ch[i][j]-64]=j;
				if((ch[i][j]>=65&&ch[i][j]<=90)&&mx<ch[i][j])
				{
					mxx=i,mxy=j;
					mx=ch[i][j];
				}
				vis[i][j]=cst[i][j]=0;
			}
		}
		nw=cnt='A';
		if(mx==cnt)
		{
			vis[mxx][mxy]=1;
			cst[mxx][mxy]=0;
			goto prnt;
		}
		bfs(capx[1],capy[1]);
		while(1)
		{
			cnt=nw;
			if(vis[mxx][mxy])
				break;
			x=capx[cnt-64];
			y=capy[cnt-64];
			rep(i,0,n)
			{
				rep(j,0,n)
					vis_nxt[i][j]=vis[i][j]=0;
			}
			bfs_nxt(x,y);
			if(nw==cnt)
				break;
			x=capx[cnt-64];
			y=capy[cnt-64];
			bfs(x,y);
		}
prnt:
		if(vis[mxx][mxy]||vis_nxt[mxx][mxy])
			printf("Case %d: %d\n",cs++,cst[mxx][mxy]);
		else 
			printf("Case %d: Impossible\n",cs++);
    }
   	return 0;
}
