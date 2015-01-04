#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
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

int min(int a,int b)
{
    return a<b?a:b;
}

typedef __int64 i64;
int a[si],tree[400030],qq;

void build(int node,int lft,int rht)
{
    int mid,l_chld,r_chld;
    if(lft==rht)
    {
        tree[node]=a[lft];
        return ;
    }

    mid=(lft+rht)/2;
    l_chld=node*2;
    r_chld=node*2+1;
    build(l_chld,lft,mid);
    build(r_chld,mid+1,rht);
    tree[node]=min(tree[l_chld],tree[r_chld]);
    return ;
}

int find(int node,int lft,int rht,int p,int q)
{
    if(lft>q||rht<p)
    return inf;
    if(lft>=p&&rht<=q)
    return tree[node];
    int l_chld,r_chld,mid;
    mid=(lft+rht)/2;
    l_chld=node*2;
    r_chld=node*2+1;
    return min(find(l_chld,lft,mid,p,q),find(r_chld,mid+1,rht,p,q));
}

int main()
{
    int i,j,mn,n,x=1,t;
	scanf("%d",&t);
	while(t--)
	{
	 //   mem(tree,0);
		scanf("%d%d",&n,&qq);
		for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        build(1,1,n);

		printf("Case %d:\n",x++);
		while(qq--)
		{
			scanf("%d%d",&i,&j);
			mn=find(1,1,n,i,j);
			printf("%d\n",mn);
		}
	}
	return 0;
}
