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
#               topcoder = Mukit09                                    #
#               codechef = mukit_mkbs                                 #
#               uva = Mukit09                                         #
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
#define si 25
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
int i,j,l,n,cs=1,fg,chair[si], a[si], m, ans, cnt, sz;
vector<int>ve[si];

void init()
{
    ans = 0;
    sz = n;

    fr(i,1,n)
    {
        ve[i].clear();
        a[i] = i;
    }

    fr(i,1,m)
    chair[i] = 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int t, ind, p, lstP, found;
    scanf("%d", &t);
   	while(t--)
   	{
   	    scanf("%d%d",&n, &m);

        init();

		ind = 1;
		while(1)
		{
            lstP = chair[ind];
		    ans += 5;
		    i = 1;
		    cnt = found = 0;
		    while(i <= sz)
		    {
		        p = a[i];
		        i++;
		        l = ve[p].size();
		        if(l == m)
                continue;

		        fg = 1;

		        rep(j,0,l)
		        {
		            if(ve[p][j] == ind)
		            {
		                fg = 0;
		                break;
		            }
		        }
		        if(fg)
		        {
		            found = 1;

		            fr(j, i, sz)
		            a[j-1] = a[j];

		            chair[ind] = p;
		            sz--;

		            if(lstP && ve[lstP].size() < m)
                    {
                        ve[lstP].pb(ind);
                        if(ve[lstP].size() < m)
                        {
                            sz++;
                            a[sz] = lstP;
                        }
                    }

		            break;
		        }
		    }

		    if(lstP && ve[lstP].size() < m && !found)
            {
                ve[lstP].pb(ind);
                if(ve[lstP].size() < m)
                {
                    sz++;
                    a[sz] = lstP;
                }
                chair[ind] = 0;
            }
		    i = 1;
		    while(i <= n)
		    {
		        if(ve[i].size() == m)
		        cnt++;

		        if(cnt == n)
		            goto prnt;

		        i++;
		    }

		    ind++;
		    if(ind > m)
		    ind = 1;
		    lstP = 0;
		}
		prnt:
		printf("Case %d: %d\n", cs++, ans);
    }
   	return 0;
}
