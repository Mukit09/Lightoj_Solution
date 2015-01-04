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
#define si 1010
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
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l=1,n,x=1,cnt,sm,fg,a[si],pr[500],cst[si],m,visit[si];
queue<int>q;

/*
i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}*/

void sieve()
{
	int num=1010,sq=sqrt(num),i,j;
	a[0]=a[1]=1;
	pr[l++]=2;
	for(i=3;i<=num;i+=2)
	{
		if(a[i]==0)
		{
			pr[l++]=i;
			if(sq>=i)
			{
				for(j=i*i;j<=num;j+=2*i)
					a[j]=1;
			}
		}
		a[i+1]=1;
	}
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

/*
i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}
*/

void bfs(int u)
{
	int i,v;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		for(i=1;i<l;i++)
		{
			if(u+pr[i]>m)
				break;
			if(u%pr[i]==0)
			{
				v=u+pr[i];
				if(visit[v]==0)
				{
					visit[v]=1;
					cst[v]=cst[u]+1;
					if(v==m)
					{
						fg=1;
						while(!q.empty())
							q.pop();
						break;
					}
					q.push(v);
				}
			}
		}
		if(!q.empty())
			q.pop();
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	sieve();
	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d",&n,&m);
		if(n==m)
		{
			printf("Case %d: 0\n",x++);
			continue;
		}
		if(!a[n]||!a[m])
		{
			printf("Case %d: -1\n",x++);
			continue;
		}
		fg=0;
		fr(i,n,m)
			visit[i]=0;
		cst[n]=0;
		bfs(n);
		if(fg)
			printf("Case %d: %d\n",x++,cst[m]);
		else
			printf("Case %d: -1\n",x++);
    }
   	return 0;
}