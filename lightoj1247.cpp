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
#define si 1000010
#define pi acos(-1.0)
#define inf (1<<30)-1

typedef long long i64;

int i,j,t,n,x=1,m,sm;

int main()
{
	i64 nw,xr;
	scanf("%d",&t);
    while(t--)
    {
		scanf("%d%d",&n,&m);
		xr=0;
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&nw);
				sm+=nw;
			}
			xr=xr^sm;
		}
		if(xr)
			printf("Case %d: Alice\n",x++);
		else
			printf("Case %d: Bob\n",x++);
    }
    return 0;
}
