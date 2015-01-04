#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>mp;
int t,i,n,fg,a[10001],x=1;

int main()
{
	int lft,rht;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		sort(a,a+n);
		fg=0;
		for(i=1;i<=n;i++)
		{
			lft=i-1;
			if(mp[lft]==0)
			{
				rht=n-i;
				if(mp[rht]==0)
					fg=1;
				else
					mp[rht]--;
			}
			else
				mp[lft]--;
			if(fg)
				break;
		}
		if(fg)
			printf("Case %d: no\n",x++);
		else
			printf("Case %d: yes\n",x++);
		mp.clear();
	}
	return 0;
}