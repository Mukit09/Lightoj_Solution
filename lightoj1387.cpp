#include<stdio.h>

int main()
{
	char ch[100];
	long t,n,sum=0,k=1,i;
	scanf("%ld",&t);
	while(t--)
	{
		sum=0;
		printf("Case %ld:\n",k++);
		scanf("%ld",&i);
		while(i--)
		{
			scanf("%s",ch);
			if(ch[0]=='d')
			{
				scanf("%ld",&n);
				sum+=n;
			}
			else
				printf("%ld\n",sum);
		}
	}
	return 0;
}