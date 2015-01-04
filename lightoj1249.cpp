#include<stdio.h>

int main()
{
	long t,k=1,h,l,w,n,i,flag,max,min,high,low;
	long a[120];
	char ch[120][30];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		flag=0;
		scanf("%s%ld%ld%ld",ch[1],&l,&w,&h);
		max=min=a[1]=l*w*h;
		low=high=1;
		for(i=2;i<=n;i++)
		{
			scanf("%s%ld%ld%ld",ch[i],&l,&w,&h);
			a[i]=l*w*h;
			if(a[i]>max)
			{
				flag=1;
				max=a[i];
				high=i;
			}
			if(a[i]<min)
			{
				flag=1;
				min=a[i];
				low=i;
			}
		}
		if(flag)
			printf("Case %ld: %s took chocolate from %s\n",k++,ch[high],ch[low]);
		else
			printf("Case %ld: no thief\n",k++);
	}
	return 0;
}
