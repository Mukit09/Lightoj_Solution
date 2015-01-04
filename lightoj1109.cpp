#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct ss
{
	long cnt,num;
}T[1010];

bool cmp(ss aa,ss bb)
{
	if(aa.cnt==bb.cnt)
		return aa.num>bb.num;
	return aa.cnt<bb.cnt;
}

int main()
{
	long count[1100];
	long t,i,j,x=1,c,a,n;

	for(i=1;i<=1000;i++)
		count[i]=0;

	for(i=1;i<=1000;i++)
	{
		c=0;
		for(j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				a=i/j;
				if(a!=j)
					c+=2;
				else
					c++;
			}
		}
		T[i-1].cnt=c;
		T[i-1].num=i;
	}
	sort(T,T+1000,cmp);

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("Case %ld: %ld\n",x++,T[n-1].num);
	}
	return 0;
}