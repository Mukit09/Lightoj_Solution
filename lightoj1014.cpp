#include<stdio.h>
#include<math.h>
#include<algorithm>
#define si 100010
using namespace std;

long res[si];

int main()
{
	long i,j,k,t,n,l,p,x=1,fg;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&p,&l);
		n=p-l;
		j=fg=0;
		for(i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				k=n/i;
				if(i>l)
				{
					fg=1;
					res[j++]=i;
				}
				if(k>l&&i!=k)
				{
					fg=1;
					res[j++]=k;
				}
			}
		}
		sort(res,res+j);
		printf("Case %ld:",x++);
		if(fg)
		{
			for(i=0;i<j;i++)
				printf(" %ld",res[i]);
		}
		else
			printf(" impossible");
		puts("");
	}
	return 0;
}
