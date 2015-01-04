#include<stdio.h>

long t,i,beg,end,n,q,mid,a[100010],aa,ab,st,ed,x=1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		printf("Case %ld:\n",x++);
		while(q--)
		{
			scanf("%ld%ld",&aa,&ab);
			if(aa>a[n]||ab<a[1])
			{
				printf("0\n");
				continue;
			}
			beg=1;end=n;
			while(beg<=end)
			{
				mid=(beg+end)/2;
				if(a[mid]>aa)
					end=mid-1;
				else if(a[mid]<aa)
					beg=mid+1;
				else
				{
					beg=mid;
					break;
				}
			}
			st=beg;
			beg=1;end=n;
			while(beg<=end)
			{
				mid=(beg+end)/2;
				if(a[mid]>ab)
					end=mid-1;
				else if(a[mid]<ab)
					beg=mid+1;
				else
				{
					end=mid;
					break;
				}
			}
			ed=end;
			printf("%ld\n",ed-st+1);
		}

	}
	return 0;
}

