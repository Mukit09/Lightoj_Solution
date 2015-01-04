#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
#define si 10000002
map<int,int>mp;
bool ara[si];
int pr[800000],ll=1,store[800000];

void sieve()
{
	long long num=si-2,i,j,root;
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

int main()
{
	int t,i,x=1,j,l;
	long long n,cnt;
	scanf("%d",&t);
	sieve();
	while(t--)
	{
		scanf("%lld",&n);
		cnt=0;
		j=1;
		l=sqrt(n)+1;
		for(i=1;pr[i]<=l&&i<ll;i++)
		{
			if(n%pr[i]==0)
			{
				cnt=0;
				while(n%pr[i]==0)
				{
					n/=pr[i];
					cnt++;
				}
				mp[pr[i]]=cnt;
				store[j++]=pr[i];
				l=sqrt(n);
			}
		}
		if(n>1)
		{
			mp[n]=1;
			store[j++]=n;
		}
		cnt=1;
		for(i=1;i<j;i++)
		{
			n=store[i];
			cnt*=(2*mp[n]+1);
		}
		cnt=(cnt+1)/2;
		printf("Case %d: %lld\n",x++,cnt);
	}
	return 0;
}
