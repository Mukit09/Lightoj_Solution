#include<stdio.h>
#include<math.h>
#define max(a,b) (a>b ?a:b)
#define si 50010

bool ara[si];
int pr[si],ll=1;

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	ara[0]=ara[1]=1;
	pr[ll++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

int main()
{
	long long i,t,x=1,sq,fg,sgn,n,one,in,mx,cnt,first,g_cd;
	sieve();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sgn=0;
		if(n<0)
		{
			n*=-1;
			sgn=1;
		}
		sq=sqrt(n);
		fg=0;
		mx=-1;
		one=in=0;
		first=1;
		for(i=1;pr[i]<=sq&&i<ll;i++)
		{
			if(n%pr[i]==0)
			{
				in++;
				cnt=0;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					cnt++;
					if(n==1)
					{
						fg=1;
						break;
					}
				}
				mx=max(cnt,mx);
				if(cnt!=mx)
				{
					one=1;
					if(first)
					{
						first=0;
						g_cd=cnt;
					}
					else
						g_cd=gcd(g_cd,cnt);
				}
				if(fg)
					break;
				sq=sqrt(n);
			}
		}
		if(n>1)
		{
			cnt=1;
			mx=max(mx,cnt);
			if(mx!=cnt)
			{
				one=1;
				if(first)
				{
					first=0;
					g_cd=cnt;
				}
				else
					g_cd=gcd(g_cd,cnt);
			}
		}
		if((in>1&&one))
			cnt=g_cd;

		if(sgn&&cnt%2==0)
		{
			while(cnt%2==0)
				cnt/=2;
		}
		printf("Case %lld: %lld\n",x++,cnt);
	}
	return 0;
}
