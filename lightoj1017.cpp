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
#define si 105
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
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,x=1,cnt,sm,fg,a[si],res[si],dp[si][si],k,w;

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

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


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

struct ss
{
    int x,y;
}stru[si];

bool cmp(ss aa,ss bb)
{
    return aa.y<bb.y;
}

int rec(int ind,int cnt)
{
    if(ind==n)
    return cnt<=k?0:-inf;
    if(cnt>k)
    return -inf;
    int &ret=dp[ind][cnt];
    if(ret!=-1)
    return ret;
    ret=res[ind]+rec(ind+res[ind],cnt+1);
    ret=max(ret,rec(ind+1,cnt));
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d%d",&n,&w,&k);
		sm=cnt=0;
		fg=1;
		rep(i,0,n)
        scanf("%d%d",&stru[i].x,&stru[i].y);
        mem(dp,-1);
        sort(stru,stru+n,cmp);
        rep(i,0,n)
        {
            res[i]=1;
            rep(j,i+1,n)
            {
                if(stru[i].y+w>=stru[j].y)
                res[i]++;
                else
                break;
            }
        }
        printf("Case %d: %d\n",x++,rec(0,0));
    }
   	return 0;
}
