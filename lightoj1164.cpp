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
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two poi64s
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __i6464 i64;
typedef long long i64;

i64 dx[]={0,0,1,-1};
i64 dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,cnt,sm,fg,u,v,w;

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

i64 gcd(i64 a,i64 b)
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
i64 ara[si],cnt_p=1,pr[si];

void sieve()
{
	i64 num=si-5,i,j,root;
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
    i64 sm,prop;
}tree[3*si];

void build(i64 node,i64 lft,i64 rht)
{
    if(lft==rht)
    {
        tree[node].sm=tree[node].prop=0;
        return;
    }
    i64 lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    build(lc,lft,m);
    build(rc,m+1,rht);
    tree[node].prop=tree[node].sm=0;
}

void update(i64 node,i64 lft,i64 rht)
{
    if(lft>v||rht<u)
    return;
    if(lft>=u&&rht<=v)
    {
        tree[node].sm+=(w*(rht-lft+1));
        tree[node].prop+=w;
        return;
    }
    i64 lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    update(lc,lft,m);
    update(rc,m+1,rht);
    tree[node].sm=tree[lc].sm+tree[rc].sm+tree[node].prop*(rht-lft+1);
    return ;
}

i64 query(i64 node,i64 lft,i64 rht,i64 tot)
{
    if(lft>v||rht<u)
    return 0;
    if(lft>=u&&rht<=v)
    return tree[node].sm+tot*(rht-lft+1);
    i64 lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    return query(lc,lft,m,tot+tree[node].prop)+query(rc,m+1,rht,tot+tree[node].prop);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    i64 t,q;
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld",&n);
   	    build(1,1,n);
   	    scanf("%lld",&q);
   	    printf("Case %lld:\n",cs++);
		while(q--)
		{
		    i64 chk;
		    scanf("%lld",&chk);
		    if(!chk)
		    {
		        scanf("%lld%lld%lld",&u,&v,&w);
		        u++,v++;
		        update(1,1,n);
		    }
		    else
		    {
		        scanf("%lld%lld",&u,&v);
		        u++,v++;
		        i64 ans=query(1,1,n,0);
		        printf("%lld\n",ans);
		    }
		}
    }
   	return 0;
}
