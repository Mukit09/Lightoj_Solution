#include<stdio.h>

char ch[110];

int main()
{
	long i,n,k=1,t,c;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%s",ch);
		c=0;
		for(i=0;i<n;i++)
		{
			if(ch[i]=='.')
			{
				c++;
				i+=2;
			}
		}
		printf("Case %ld: %ld\n",k++,c);
	}
	return 0;
}