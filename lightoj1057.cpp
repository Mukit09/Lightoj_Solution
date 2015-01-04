		/****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |	     -----  /-------------\   #
#   |   \   /   |  |           |   |    /      |           |          #
#   |    \ /    |  |           |   |  /        |           |          #
#   |           |  |           |   |/          |           |          #
#   |           |  |           |   |\          |           |          #
#   |           |  |           |   |  \        |           |          #
#   |           |   \         /    |    \      |           |          #
#  ---         ---   \______ /     |         -----       -----        #
#                                                                     #
#                                                                     #
#                                                                     #
#    			codeforces = Mukit09                                  #
#    			topcoder = mukitmkbs25                                #
#    			codechef = mukit_mkbs                                 #
#    			uva = mkbs_cse09                                      #
#    			spoj = mkbs_cse09                                     #
#    			CSE, CUET                                             #
#    facebook : https://www.facebook.com/hesitated.mkbs?ref=tn_tnmn   #
#                                                                     #
#                                                                     #
\*********************************************************************/

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
#define si 17
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define pb push_back
#define mpair make_pair
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < eps ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
int l,n,cs=1,cst[21][21],dp[1<<si][si],m,NN,a[21][21],dis[si][si];
char ch[21][21];

struct ss
{
    int x,y;
}stru[si];

void bfs(int u,int v)
{
    queue<int>q;
    q.push(u);
    q.push(v);
    cst[u][v]=0;
    int i,i1,i2,nwu,nwv;
    i1=a[u][v];
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        v=q.front();
        q.pop();
        rep(i,0,8)
        {
            nwu=u+dx[i];
            nwv=v+dy[i];
            if(nwu>=0&&nwv>=0&&nwu<n&&nwv<m&&cst[nwu][nwv]<0)
            {
                q.push(nwu);
                q.push(nwv);
                cst[nwu][nwv]=cst[u][v]+1;
                i2=a[nwu][nwv];
                if(ch[nwu][nwv]!='.')
                dis[i1][i2]=cst[nwu][nwv];
            }
        }
    }
}

int rec(int mask,int node)
{
    if(mask==NN)
    return dis[node][l];
    int &ret=dp[mask][node];
    if(ret!=-1)
    return ret;

    ret=inf;
    int i,j,u,v,i1,i2;
    for(i=0;i<l;i++)
    {
        if(!(mask&(1<<i)))
        ret=min(ret,rec(mask|(1<<i),i)+dis[node][i]);
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t,i,j,stx,sty,k,u,v;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d",&n,&m);
   	    l=0;
   	    rep(i,0,n)
   	    {
   	        scanf("%s",ch[i]);
   	        rep(j,0,m)
   	        {
   	            a[i][j]=0;
   	            if(ch[i][j]=='x')
   	            stx=i,sty=j;
   	            if(ch[i][j]=='g')
   	            {
   	                stru[l].x=i;
   	                stru[l].y=j;
   	                a[i][j]=l;
   	                l++;
   	            }
   	        }
   	    }
   	    stru[l].x=stx;
   	    stru[l].y=sty;

   	    a[stx][sty]=l;
   	    rep(i,0,l+1)
   	    {
   	        rep(j,0,n)
   	        {
   	            rep(k,0,m)
   	            cst[j][k]=-1;
   	        }
   	        u=stru[i].x;
   	        v=stru[i].y;
   	        dis[i][i]=0;
   	        bfs(u,v);
   	    }
   	    NN=(1<<l)-1;
   	    mem(dp,-1);
   	    printf("Case %d: %d\n",cs++,rec(0,l));
    }
   	return 0;
}
