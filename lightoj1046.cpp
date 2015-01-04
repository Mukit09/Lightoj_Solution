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
#define si 11
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

int dirx[]={-2,-1,-2,-1,2,1,2,1};
int diry[]={-1,-2,1,2,-1,-2,1,2};
int i,j,l,x=1,vis[si][si],cst[si][si],res[si][si],cnt[si][si],X,Y;
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

void bfs(int u,int v,int digit)
{
	int i,nwx,nwy,chk;
	vis[u][v]=1;
	cnt[u][v]++;
	q.push(u);
	q.push(v);
	q.push(0);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		chk=q.front();
		q.pop();
		rep(i,0,8)
		{
			nwx=dirx[i]+u;
			nwy=diry[i]+v;
			if(nwx<X&&nwx>=0&&nwy>=0&&nwy<Y&&vis[nwx][nwy]==0)
			{
				vis[nwx][nwy]=1;
				cst[nwx][nwy]=(chk+1)/digit+1;
				if((chk+1)%digit==0)
					cst[nwx][nwy]--;
				res[nwx][nwy]+=cst[nwx][nwy];
				cnt[nwx][nwy]++;
				q.push(nwx);
				q.push(nwy);
				q.push(chk+1);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t,k;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d",&X,&Y);
		rep(i,0,X)
		{
			scanf("%s",&ch[i]);
			rep(j,0,Y)
				res[i][j]=cnt[i][j]=0;
		}
		int mx=0;
		rep(i,0,X)
		{
			rep(j,0,Y)
			{
				if(ch[i][j]>=49&&ch[i][j]<=57)
				{
					mx++;
					cst[i][j]=0;
					rep(k,0,X)
					{
						rep(l,0,Y)
							vis[k][l]=0;

					}
					bfs(i,j,ch[i][j]-48);
				}
			}
		}
		int mn=inf,fg=0;
		rep(i,0,X)
		{
			rep(j,0,Y)
			{
				if(cnt[i][j]==mx)
				{
					fg=1;
					mn=min(mn,res[i][j]);
				}
			}
		}
		if(fg)
			printf("Case %d: %d\n",x++,mn);
		else
			printf("Case %d: -1\n",x++);
    }
   	return 0;
}
