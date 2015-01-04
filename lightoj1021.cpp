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
#define si 18
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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 l,b,cs=1,NN,k,dp[65600][21];
char ch[si];

i64 rec(i64 mask,i64 md)
{
    if(mask==NN)
    return md==0;
    i64 &ret=dp[mask][md];
    if(ret!=-1)
    return ret;

    i64 i;
    ret=0;
    for(i=0;i<l;i++)
    {
        if(!(mask&(1<<i)))
        {
            i64 v;
            if(ch[i]>=48&&ch[i]<=57)
            v=md*b+(ch[i]-48);
            else
            v=md*b+(ch[i]-55);
            v%=k;
            ret+=rec(mask|(1<<i),v);
        }
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    i64 t;
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld%lld%s",&b,&k,ch);
   	    l=strlen(ch);
   	    NN=pow(2,l)-1;
   	    mem(dp,-1);
   	    printf("Case %lld: %lld\n",cs++,rec(0,0));
    }
   	return 0;
}
