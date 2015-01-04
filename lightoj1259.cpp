#include<stdio.h>
#include<math.h>
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define si 10000010
#define si_pr 700000

int ara[si/32],ll=1,pr[si_pr];

int check(int m,int pos)
{
	return (m&(1<<pos));
}

int set(int m,int pos)
{
	return (m|(1<<pos));
}

void sieve()
{
	int i,j,num=si-5,root=sqrt(num);
	pr[ll++]=2;
	for(i=3;i<=num;i+=2)
	{
		if(check(ara[i>>5],i&31)==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j>>5]=set(ara[j>>5],j&31);
			}
		}
	}
}

int main()
{
	int l,h,i,j,k,fg,nn,m,n,x=1,cnt,t;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=1;h=ll-1;
		nn=n/2;
		while(l<=h)
		{
			m=(l+h)/2;
			if(pr[m]>nn)
				h=m-1;
			else
				l=m+1;
		}
		cnt=0;
		for(i=h;i>=1;i--)
		{
			m=n-pr[i];
			if(m<=1)
				break;
			if((m%2==0&&m!=2))
				continue;
			if(check(ara[m>>5],m&31)==0)
				cnt++;
		}
		printf("Case %d: %d\n",x++,cnt);
	}
	return 0;
}