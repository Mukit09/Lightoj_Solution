#include<stdio.h>
#include<string.h>

long a1[100],a2[100],t,i,cnt,x=1,fg;
char ch1[110],ch2[110];

int main()
{
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch1);
		gets(ch2);

		for(i=65;i<=90;i++)
			a1[i]=a2[i]=0;

		for(i=0;ch1[i];i++)
		{
			if(ch1[i]>90)
				ch1[i]-=32;
			if(ch1[i]>=65&&ch1[i]<=90)
				a1[ch1[i]]++;
		}
		for(i=0;ch2[i];i++)
		{
			if(ch2[i]>90)
				ch2[i]-=32;
			if(ch2[i]>=65&&ch2[i]<=90)
				a2[ch2[i]]++;
		}
		fg=0;
		for(i=65;i<=90;i++)
		{
			if(a1[i]>a2[i])
			{
				fg=1;
				break;
			}
		}
		for(i=65;i<=90;i++)
		{
			if(a2[i]>a1[i])
			{
				fg=1;
				break;
			}
		}
		if(fg)
			printf("Case %ld: No\n",x++);
		else
			printf("Case %ld: Yes\n",x++);
	}
	return 0;
}