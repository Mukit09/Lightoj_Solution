        /****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |         -----  /-------------\   #
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
#               codeforces = Mukit09                                  #
#               topcoder = mukitmkbs25                                #
#               codechef = mukit_mkbs                                 #
#               uva = mkbs_cse09                                      #
#               spoj = mkbs_cse09                                     #
#               CSE, CUET                                             #
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
#define si 1000010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 100000007 //10^9

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
i64 i,j,l,n,cs=1,sv[102510],u,v,cat[si],fact[2*si];

i64 b_search(i64 v)
{
    i64 lo=1;
    i64 hi=j-1;
    i64 mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(sv[mid]>v)
        hi=mid-1;
        else if(sv[mid]<v)
        lo=mid+1;
        else return mid;
    }
    return lo;
}

map<i64,bool>mp;

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

void catalan()
{
    int i,j;
    fact[0]=1;
    fr(i,1,2e6)
    fact[i]=(fact[i-1]*i)%mod;

    fr(i,1,1e6)
    {
        cat[i]=fact[2*i];
        i64 nw=bmod(fact[i],mod-2);
        if(nw<0)
        nw+=mod;
        cat[i]=(cat[i]*nw)%mod;
        nw=bmod(fact[i+1],mod-2);
        if(nw<0)
        nw+=mod;
        cat[i]=(cat[i]*nw)%mod;
    }
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    j=1;
    fr(i,2,1e5)
    {
        i64 nw=i*i;
        while(nw<=1e10)
        {
            if(!mp[nw])
            {
                sv[j++]=nw;
                mp[nw]=true;
            }
            nw*=i;
        }
    }
    sort(sv,sv+j);
    catalan();
    i64 t;
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld%lld",&u,&v);
   	    i64 lb=b_search(u);
   	    i64 hb=b_search(v);
   	    if(sv[hb]>v)
   	    hb--;
   	    i64 tot=hb-lb+1;
   	    printf("Case %lld: %lld\n",cs++,cat[tot]);
    }
   	return 0;
}
