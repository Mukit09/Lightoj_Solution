#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b ?a:b)
#define si 1000010

int a[si],cnt_five[si],cnt_two[si];

void pre_cal()
{
	int i,cnt,m;
	cnt_five[1]=cnt_two[1]=0;
	for(i=2;i<=si-5;i++)
	{
		m=i;
		if(m%5==0)
		{
			cnt=0;
			while(m%5==0)
			{
				cnt++;
				m/=5;
			}
			cnt_five[i]=cnt+cnt_five[i-1];
		}
		else
			cnt_five[i]=cnt_five[i-1];
		if(m%2==0)
		{
			cnt=0;
			while(m%2==0)
			{
				cnt++;
				m/=2;
			}
			cnt_two[i]=cnt+cnt_two[i-1];
		}
		else
			cnt_two[i]=cnt_two[i-1];
	}
}

int main()
{
	pre_cal();
	int n,r,p,q,t,tw,fi,cnt,x=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&r,&p,&q);

		fi=cnt_five[n]-cnt_five[r]-cnt_five[n-r];
		tw=cnt_two[n]-cnt_two[r]-cnt_two[n-r];
		
		cnt=0;
		while(p%5==0)
		{
			p/=5;
			cnt++;
		}
		cnt*=q;
		fi+=cnt;

		cnt=0;
		while(p%2==0)
		{
			p/=2;
			cnt++;
		}
		cnt*=q;
		tw+=cnt;
		printf("Case %d: %d\n",x++,min(fi,tw));
	}
	return 0;
}