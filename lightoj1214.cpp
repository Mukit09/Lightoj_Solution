#include<stdio.h>
#include<string.h>

int main()
{
	long long t,k=1,i,n,s,l;
	char ch[250];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s%lld",ch,&n);
		l=strlen(ch);
		s=0;
		for(i=0;i<l;i++)
		{
			if(ch[i]=='-')
				continue;
			s=s*10+(ch[i]-48);
			s%=n;
		}
		if(s==0)
			printf("Case %lld: divisible\n",k++);
		else
			printf("Case %lld: not divisible\n",k++);
	}
	return 0;
}