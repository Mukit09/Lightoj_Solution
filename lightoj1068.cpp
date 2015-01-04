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
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int j,l,n,cs=1,fg=1,dp[12][83][83][2],vis[12][83][83][2],d,k,p,q;
char ch[12];

int rec(int pos,int smod,int nmod,int taken)
{
    if(pos==l)
    return (!smod && !nmod);
    int &ret=dp[pos][smod][nmod][taken];
    if(vis[pos][smod][nmod][taken]==fg)
    return ret;
    vis[pos][smod][nmod][taken]=fg;
    ret=0;
    int nw=ch[pos]-48,sm,nm,pre,i;
    rep(i,0,10)
    {
        if(taken&&i>nw)
        break;
        sm=(smod+i)%k;
        nm=(nmod*10+i)%k;
        pre=(i<nw)?0:taken; // i nw theke choto hole pore corresponding digit theke boro digit nite parbo
        ret+=rec(pos+1,sm,nm,pre);
    }
    return ret;
}

int ok(int n)
{
    sprintf(ch,"%d",n);
    l=strlen(ch);
    fg++;
    return rec(0,0,0,1);
}

int main()
{
	//freopen("G:\\Problems__And_Codes\\All_Codes\\input.txt", "r", stdin);
	//freopen("G:\\Problems__And_Codes\\All_Codes\\output_mine.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d%d",&p,&q,&k);

   	    if(k==1)
   	    {
   	        printf("Case %d: %d\n",cs++,q-p+1);
   	        continue;
   	    }

   	    if(k>82)
   	    {
   	        printf("Case %d: 0\n",cs++);
   	        continue;
   	    }

   	    int ans1,ans2,ans;
   	    ans1=ok(p-1);
   	    ans2=ok(q);
   	    ans=ans2-ans1;
   	    printf("Case %d: %d\n",cs++,ans);
    }
   	return 0;
}
