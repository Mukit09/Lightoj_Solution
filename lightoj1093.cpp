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
#define si 100010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;
typedef long long i64;

int max(int a,int b)
{
    return a>b?a:b;
}

int min(int a,int b)
{
    return a<b?a:b;
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,cnt,sm,fg,a[si],d,u,v;

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

/*
int ara[si],cnt_p=1,pr[si];

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	pr[cnt_p++]=2;
	ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
		    pr[cnt_p++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}
*/

struct ss
{
    int mx,mn;
}tree[si*3];

void build(int node,int lft,int rht)
{
    if(lft==rht)
    {
        tree[node].mx=tree[node].mn=a[lft];
        return;
    }
    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    build(lc,lft,m);
    build(rc,m+1,rht);
    tree[node].mx=max(tree[lc].mx,tree[rc].mx);
    tree[node].mn=min(tree[lc].mn,tree[rc].mn);
}

int query_mx(int node,int lft,int rht)
{
    if(lft>v||rht<u)
    return -inf;
    if(lft>=u&&rht<=v)
    return tree[node].mx;

    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    return max(query_mx(lc,lft,m),query_mx(rc,m+1,rht));
}

int query_mn(int node,int lft,int rht)
{
    if(lft>v||rht<u)
    return inf;
    if(lft>=u&&rht<=v)
    return tree[node].mn;

    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    return min(query_mn(lc,lft,m),query_mn(rc,m+1,rht));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d",&n,&d);

		fr(i,1,n)
        scanf("%d",&a[i]);
        if(d==1)
        {
            printf("Case %d: 0\n",cs++);
            continue;
        }

        build(1,1,n);
        int mx=-1;
        fr(i,1,n-d+1)
        {
            u=i;
            v=i+d-1;
            mx=max(mx,query_mx(1,1,n)-query_mn(1,1,n));
        }
        printf("Case %d: %d\n",cs++,mx);
    }
   	return 0;
}
