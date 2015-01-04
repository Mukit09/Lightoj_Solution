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

typedef __int64 i64;
#define i64 long long

int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int i,j,l,n,x,cs=1,y,r,o,s,u,v,w,z,fg,cst[si][si][si][si][si][si],tx[4],ty[4],x1,x2,x3,y2,y3,k;
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

int check(int a,int b,int c,int d,int e,int f)
{
	if((a<0||a>=n||b>=n||b<0||ch[a][b]=='#')&&(c<0||c>=n||d>=n||d<0||ch[c][d]=='#')&&(e<0||e>=n||f>=n||f<0||ch[e][f]=='#'))
		return 0;
	if(a==c&&a==e&&b==d&&b==f)
		return 0;
	return 1;
}

int found(int a,int b,int c,int d,int e,int f)
{
	if(a==tx[0]&&b==ty[0]&&c==tx[1]&&d==ty[1]&&e==tx[2]&&f==ty[2])
		return 1;
	return 0;
}

void bfs(int a,int b,int c,int d,int e,int f)
{
	int nwa,nwb,nwc,nwd,nwe,nwf,i,chk;
	q.push(a);
	q.push(b);
	q.push(c);
	q.push(d);
	q.push(e);
	q.push(f);
	while(!q.empty())
	{
		a=q.front();q.pop();
		b=q.front();q.pop();
		c=q.front();q.pop();
		d=q.front();q.pop();
		e=q.front();q.pop();
		f=q.front();q.pop();
		if(!fg)
		{
			rep(i,0,4)
			{
				nwa=a+dirx[i];
				nwb=b+diry[i];
				nwc=c+dirx[i];
				nwd=d+diry[i];
				nwe=e+dirx[i];
				nwf=f+diry[i];
				chk=check(nwa,nwb,nwc,nwd,nwe,nwf);
				if(!chk)
					continue;
				if(nwa<0||nwa==n||nwb<0||nwb==n||ch[nwa][nwb]=='#')
					nwa=a,nwb=b;
				if(nwc<0||nwc==n||nwd<0||nwd==n||ch[nwc][nwd]=='#')
					nwc=c,nwd=d;
				if(nwe<0||nwe==n||nwf<0||nwf==n||ch[nwe][nwf]=='#')
					nwe=e,nwf=f;

				if(nwa==nwc&&nwb==nwd&&(e<0||e==n||f<0||f==n||ch[e][f]=='#'))
					continue;
				else if(nwa==nwc&&nwb==nwd)
					nwa=a,nwb=b,nwc=c,nwd=d;

				if(nwa==nwe&&nwb==nwf&&(c<0||c==n||d<0||d==n||ch[c][d]=='#'))
					continue;
				else if(nwa==nwe&&nwb==nwf)
					nwa=a,nwb=b,nwe=e,nwf=f;

				if(nwe==nwc&&nwf==nwd&&(a<0||a==n||b<0||b==n||ch[a][b]=='#'))
					continue;
				else if(nwe==nwc&&nwf==nwd)
					nwe=e,nwf=f,nwc=c,nwd=d;

				if(cst[nwa][nwb][nwc][nwd][nwe][nwf]==-1)
				{
					cst[nwa][nwb][nwc][nwd][nwe][nwf]=cst[a][b][c][d][e][f]+1;
					if(found(nwa,nwb,nwc,nwd,nwe,nwf)==1||found(nwa,nwb,nwe,nwf,nwc,nwd)==1||found(nwc,nwd,nwa,nwb,nwe,nwf)==1||found(nwc,nwd,nwe,nwf,nwa,nwb)==1||found(nwe,nwf,nwa,nwb,nwc,nwd)==1||found(nwe,nwf,nwc,nwd,nwa,nwb)==1)
					{
						o=nwa,s=nwb,u=nwc,v=nwd,w=nwe,z=nwf;
						fg=1;
						break;
					}
					q.push(nwa);
					q.push(nwb);
					q.push(nwc);
					q.push(nwd);
					q.push(nwe);
					q.push(nwf);
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t,p,q,r;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d",&n);
		k=fg=0;
		rep(i,0,n)
		{
			scanf("%s",ch[i]);
			rep(j,0,n)
			{
				if(ch[i][j]=='X')
					tx[k]=i,ty[k++]=j;
				else if(ch[i][j]=='A')
					x=i,y=j;
				else if(ch[i][j]=='B')
					x2=i,y2=j;
				else if(ch[i][j]=='C')
					x3=i,y3=j;
			}
		}
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				rep(k,0,n)
				{
					rep(p,0,n)
					{
						rep(q,0,n)
						{
							rep(r,0,n)
								cst[i][j][k][p][q][r]=-1;
						}
					}
				}
			}
		}
		cst[x][y][x2][y2][x3][y3]=0;
		bfs(x,y,x2,y2,x3,y3);
		if(!fg)
			printf("Case %d: trapped\n",cs++);
		else
			printf("Case %d: %d\n",cs++,cst[o][s][u][v][w][z]);
    }
   	return 0;
}