#include<stdio.h>
#include<algorithm>
#define si 50010
using namespace std;

struct ss
{
	long x,y;
}stru[si];

bool cmp(ss aa,ss bb)
{
	return aa.y<bb.y;
}

int main()
{
	long t,i,cnt,w,n,x=1,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&w);
		for(i=0;i<n;i++)
			scanf("%ld%ld",&stru[i].x,&stru[i].y);
		sort(stru,stru+n,cmp);
		cnt=0;
		for(i=0;i<n;i++)
		{
			cnt++;
			if(stru[i].y+w>=stru[i+1].y)
			{
				j=i;
				while(stru[j].y+w>=stru[i+1].y)
					i++;
			}
		}
		printf("Case %ld: %ld\n",x++,cnt);
	}
	return 0;
}
