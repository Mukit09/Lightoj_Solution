#include<stdio.h>
#include<math.h>
#define neg_inf -2147483648
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define si 100001
int lis[si],a[si],chk[si],cs=1;

void bsearch(int lo,int hi,int key)
{
	int mid;
	while(lo<=hi)
	{
		mid=(lo+hi)>>1;
		if(lis[mid]==key)
			return ;
		else if(lis[mid]>key)
			hi=mid-1;
		else
			lo=mid+1;
	}
	lis[lo]=key;
}

int main()
{
	int cur,i,n,t,mx;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
		cur=0;
		lis[cur]=neg_inf;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>lis[cur])
			{
				cur++;
				lis[cur]=a[i];
			}
			else if(a[i]<lis[cur])
				bsearch(1,cur,a[i]);
			chk[i]=cur;
		}
		cur=0;
		mx=-1;
		lis[cur]=neg_inf;
		for(i=n;i>=1;i--)
		{
			if(a[i]>lis[cur])
			{
				cur++;
				lis[cur]=a[i];
			}
			else if(a[i]<lis[cur])
				bsearch(1,cur,a[i]);
			chk[i]=min(cur,chk[i]);
			if(mx<chk[i])
			mx=chk[i];
		}
		printf("Case %d: %d\n",cs++,mx*2-1);
	}
	return 0;
}
