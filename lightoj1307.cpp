#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define si 2010
int a[si];

int main()
{
	int i,j,x=1,l,h,m,tw,t,n,cnt,ind;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				tw=a[i]+a[j];
				l=j+1;
				h=n-1;
				ind=-1;
				while(l<=h)
				{
					m=(l+h)/2;
					if(a[m]<tw)
					{
						ind=m;
						l=m+1;
					}
					else
						h=m-1;
				}
				if(ind!=-1)
					cnt+=(ind-j);
			}
		}
		printf("Case %d: %d\n",x++,cnt);
	}
	return 0;
}