#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b ?a:b)
#define inf 100000000

long long t,q,beg,end,m,fg,mn,j,x=1;

long long chk(long long n)
{
	long long k=1,sm=0,b;
	while(1)
	{
		b=pow(5,k);
		if(n/b==0)
			break;
		sm+=(n/b);
		k++;
	}
	return sm;
}


int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&q);
		beg=1;
		end=mn=inf;
		fg=0;
		while(beg<=end)
		{
			m=(beg+end)/2;
			j=chk(m*5);
			if(j<q)
				beg=m+1;
			else if(j>q)
				end=m-1;
			else
			{
				fg=1;
				mn=m*5;
				break;
			}
		}
		if(fg)
			printf("Case %lld: %lld\n",x++,mn);
		else
			printf("Case %lld: impossible\n",x++);
	}
	return 0;
}