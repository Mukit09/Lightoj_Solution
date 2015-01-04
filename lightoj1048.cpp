#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b ?a:b)
#define max(a,b) (a>b ?a:b)
#define inf 99999
#define si 1010

int a[si],aa[si],res[si],beg,end,sm,mn,mx,t,k,n;

int chk(int p)
{
	int i,m=p,tk=0,j=1,x=1;
	aa[j]=a[1];
	for(i=1;i<=n;i++)
	{
		if(m<a[i])
		{
			tk++;
			if(tk==k)
				return 0;
			j++;
			if(n-i+1==k-tk)
			{
				for(x=i,tk=j;x<=n;x++,tk++)
					aa[tk]=a[x];
				break;
			}
			x=i;
			aa[j]=a[i];
			m=p;
		}
		else if(i!=x)
		{
			aa[j]+=a[i];
			if(n-i+1==k-tk)
			{
				for(x=i+1,tk=j+1;x<=n;x++,tk++)
					aa[tk]=a[x];
				break;
			}
		}
		m-=a[i];
	}
	for(j=1;j<=k;j++)
		res[j]=aa[j];
	return 1;
}

int main()
{
	int i,m,j,x=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		n++;k++;
		sm=0;
		mn=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sm+=a[i];
			mn=max(mn,a[i]);
		}
		beg=mn;
		end=sm;
		while(beg<=end)
		{
			m=(beg+end)/2;
			j=chk(m);
			if(j)
				end=m-1;
			else
				beg=m+1;
		}
		printf("Case %d: %d\n",x++,beg);
		for(j=1;j<=k;j++)
			printf("%d\n",res[j]);
	}
	return 0;
}