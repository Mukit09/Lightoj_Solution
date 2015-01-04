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

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points

typedef __int64 i64;

int i,t,n,x=1,cnt;

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

int main()
{
	int nw,xr;
	scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&n);
		xr=cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&nw);
			if(nw==1)
				cnt++;
			xr=xr^nw;
		}
		if(cnt==n&&n%2==1)
			printf("Case %d: Bob\n",x++);
		else if(cnt==n&&n%2==0)
			printf("Case %d: Alice\n",x++);
		else if(!xr)
			printf("Case %d: Bob\n",x++);
		else if(xr)
			printf("Case %d: Alice\n",x++);
    }
    return 0;
}