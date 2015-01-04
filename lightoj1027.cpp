#include<stdio.h>
#include<math.h>

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
	int t,i,sm,x=1,cnt,n,g_cd,u;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sm=cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&u);
			if(u<0)
			{
				u*=-1;
				cnt++;
			}
			sm+=u;
		}
		n-=cnt;
		if(!n)
		{
			printf("Case %d: inf\n",x++);
			continue;
		}
		g_cd=gcd(n,sm);
		n/=g_cd;
		sm/=g_cd;
		printf("Case %d: %d/%d\n",x++,sm,n);
	}
	return 0;
}
		