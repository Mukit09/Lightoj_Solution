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

typedef long long i64;

i64 t,x=1,g_cd,u,v;

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

int main()
{
	i64 x1,y1,x2,y2;
	scanf("%lld",&t);
    while(t--)
    {
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(x1>x2)
			u=x1-x2;
		else
			u=x2-x1;
		if(y1>y2)
			v=y1-y2;
		else
			v=y2-y1;
		g_cd=gcd(u,v);
		printf("Case %lld: %lld\n",x++,g_cd+1);
    }
    return 0;
}