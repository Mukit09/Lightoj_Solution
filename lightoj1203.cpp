/****** BISMILLAHIR RAHMANIR RAHIM ********/

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
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < eps ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;
typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,n,cs=1;

struct P
{
    i64 x,y;
    P(i64 x=0,i64 y=0)
    {
        this->x=x;
        this->y=y;
    }
}stru[si],pvt,C[si];

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y);} // Dot Product
i64 CP(P aa,P bb){return aa.x*bb.y-aa.y*bb.x;} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));} // Value of Vector aa
P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}//Rotaion with rad
P VL(P aa,double len){double v=VA(aa);return P(aa.x*len/v,aa.y*len/v);}// Make Vector of 'len' length

bool cmp1(P aa,P bb)
{
    if(aa.y==bb.y)
    return aa.x<bb.x;
    return aa.y<bb.y;
}

bool cmp(P aa, P bb)
{
    i64 c=CP(MV(pvt,aa),MV(pvt,bb));
    if(c)
    return c>0;
    i64 d1=dist(pvt.x,pvt.y,aa.x,aa.y);
    i64 d2=dist(pvt.x,pvt.y,bb.x,bb.y);
    return d1<d2;
}

double angle(P o,P a,P b)
{
    P oa=MV(o,a);
    P ob=MV(o,b);
    return atan2((double)oa.y,(double)oa.x)-atan2((double)ob.y,(double)ob.x);
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    double rad,a,mn;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d",&n);
		rep(i,0,n)
        scanf("%lld%lld",&stru[i].x,&stru[i].y);
        if(n<3)
        {
            printf("Case %d: 0.00000000\n",cs++);
            continue;
        }
        sort(stru,stru+n,cmp1);
        pvt=stru[0];
        sort(stru,stru+n,cmp);

        j=2;
        C[0]=stru[0];
        C[1]=stru[1];
        rep(i,2,n)
        {
            double p=CP(MV(C[j-2],C[j-1]),MV(C[j-2],stru[i]));
            while(CP(MV(C[j-2],C[j-1]),MV(C[j-2],stru[i]))<0)
            {
                p=CP(MV(C[j-2],C[j-1]),MV(C[j-2],stru[i]));
                j--;
            }
            if(stru[i].x!=C[j-1].x||stru[i].y!=C[j-1].y)
            C[j++]=stru[i];
        }

        // remove points, which are in same line
        int k=1;
        C[j]=C[0];
        rep(i,1,j)
        {
            if(area(C[k-1].x,C[k-1].y,C[i].x,C[i].y,C[i+1].x,C[i+1].y))
            C[k++]=C[i];
        }
        j=k;
        if(j<3)
        {
            printf("Case %d: 0.00000000\n",cs++);
            continue;
        }
        mn=angle(C[0],C[j-1],C[1]);
        if(mn<0.0)
        mn+=2.0*pi;
        C[j]=C[0];
        rep(i,1,j)
        {
            rad=angle(C[i],C[i-1],C[i+1]);
            if(rad<0.0)
            rad+=2.0*pi;
            if(mn>rad)
            mn=rad;
        }
        printf("Case %d: %.10lf\n",cs++,(mn*180.0)/pi);
    }
   	return 0;
}
