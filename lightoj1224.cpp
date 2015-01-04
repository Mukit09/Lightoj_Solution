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
#define si 100010
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

int i,j,l,n,cs=1,mx;
char ch[60];

struct node
{
    int cnt;
    node *nxt[5];

    node()
    {
        int i;
        for(i=0;i<4;i++)
        nxt[i]=0;
        cnt=0;
    }
}*root;

void insert()
{
    int i,j;
    node *nw=root;
    for(i=0;i<l;i++)
    {
        if(ch[i]=='A')
        j=0;
        else if(ch[i]=='C')
        j=1;
        else if(ch[i]=='G')
        j=2;
        else
        j=3;

        if(!nw->nxt[j])
        nw->nxt[j]=new node();
        nw=nw->nxt[j];
        nw->cnt++;
        if(mx<(nw->cnt)*(i+1))
        mx=(nw->cnt)*(i+1);
    }
}

void del(node *nw)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(nw->nxt[i])
        del(nw->nxt[i]);
    }
    delete(nw);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    root= new node();
   	    mx=0;
   	    scanf("%d",&n);
		fr(i,1,n)
		{
		    scanf("%s",ch);
		    l=strlen(ch);
		    insert();
		}
		printf("Case %d: %d\n",cs++,mx);
		del(root);
    }
   	return 0;
}
