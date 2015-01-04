#include<stdio.h>
#include<algorithm>
using namespace std;

long t,x=1,i,j,n,a[60],b[60],cnt,chk_a[60],chk_b[60];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			chk_a[i]=chk_b[i]=0;
			scanf("%ld",&a[i]);
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
			scanf("%ld",&b[i]);
		sort(b,b+n);
		cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--)
			{
				if(a[i]>b[j]&&!chk_a[i]&&!chk_b[j])
				{
					chk_a[i]=chk_b[j]=1;
					cnt+=2;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--)
			{
				if(a[i]==b[j]&&!chk_a[i]&&!chk_b[j])
				{
					chk_a[i]=chk_b[j]=1;
					cnt++;
					break;
				}
			}
		}
		printf("Case %ld: %ld\n",x++,cnt);
	}
	return 0;
}

