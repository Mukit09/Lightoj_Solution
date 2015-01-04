#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int a[51],x=1;

int main()
{
	int n,i,t,ans,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			ans+=(a[i]+1);
			if(a[i]==a[i+1])
			{
				cnt=a[i];
				i++;
				while(a[i]==a[i-1]&&cnt)
				{
					i++;
					cnt--;
				}
				i--;
			}
		}
		printf("Case %d: %d\n",x++,ans);
	}
	return 0;
}