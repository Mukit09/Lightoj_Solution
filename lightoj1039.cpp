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
#define si 1010
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

int dirx[]={0,0,1,0,0,-1};
int diry[]={1,0,0,-1,0,0};
int dirz[]={0,1,0,0,-1,0};
int i,j,l,n,x=1,cnt,sm,fg,a1[51][28],a2[51][28],a3[51][28],vis[27][27][27],cst[27][27][27],found,dx,dy,dz;
char ch[28],st[5],end[5];
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

void bfs(int u,int v,int w)
{
	int nwx,nwy,nwz,i,j,fg;
	q.push(u);
	q.push(v);
	q.push(w);
	vis[u][v][w]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		w=q.front();
		q.pop();
		if(!found)
		{
			rep(i,0,6)
			{
				nwx=u+dirx[i];
				nwy=v+diry[i];
				nwz=w+dirz[i];
				if(nwx>26)
					nwx=1;
				else if(nwx==0)
					nwx=26;
				if(nwy>26)
					nwy=1;
				else if(nwy==0)
					nwy=26;
				if(nwz>26)
					nwz=1;
				else if(nwz==0)
					nwz=26;
				fg=0;
				fr(j,1,n)
				{
					if(a1[j][nwx]==1&&a2[j][nwy]==1&&a3[j][nwz]==1)
					{
						fg=1;
						break;
					}
				}
				if(vis[nwx][nwy][nwz]==0&&!fg)
				{
					vis[nwx][nwy][nwz]=1;
					cst[nwx][nwy][nwz]=1+cst[u][v][w];
					if(nwx==dx&&nwy==dy&&nwz==dz)
					{
						found=1;
						break;
					}
					q.push(nwx);
					q.push(nwy);
					q.push(nwz);
				}
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
		scanf("%s%s%d",st,end,&n);

		fg=1;
		found=0;
		fr(i,1,n)
		{
			fr(j,1,26)
				a1[i][j]=a2[i][j]=a3[i][j]=0;

			scanf("%s",ch);
			l=strlen(ch);
			rep(k,0,l)
				a1[i][ch[k]-96]=1;

			scanf("%s",ch);
			l=strlen(ch);
			rep(k,0,l)
				a2[i][ch[k]-96]=1;

			scanf("%s",ch);
			l=strlen(ch);
			rep(k,0,l)
				a3[i][ch[k]-96]=1;
		}
		fr(j,1,n)
		{
			if(a1[j][st[0]-96]==1&&a2[j][st[1]-96]==1&&a3[j][st[2]-96]==1)
			{
				fg=0;
				break;
			}
			if(a1[j][end[0]-96]==1&&a2[j][end[1]-96]==1&&a3[j][end[2]-96]==1)
			{
				fg=0;
				break;
			}
		}
		if(!fg)
			printf("Case %d: -1\n",x++);
		else
		{
			if(strcmp(st,end)==0)
			{
				printf("Case %d: 0\n",x++);
				continue;
			}
			fr(i,1,26)
			{
				fr(j,1,26)
				{
					fr(k,1,26)
						vis[i][j][k]=0;
				}
			}
			cst[st[0]-96][st[1]-96][st[2]-96]=0;
			dx=end[0]-96;
			dy=end[1]-96;
			dz=end[2]-96;
			bfs(st[0]-96,st[1]-96,st[2]-96);
			if(found)
				printf("Case %d: %d\n",x++,cst[dx][dy][dz]);
			else
				printf("Case %d: -1\n",x++);
		}
    }
   	return 0;
}
