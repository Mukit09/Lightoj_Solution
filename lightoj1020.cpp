#include<stdio.h>
#include<string.h>

int main()
{
	long t,k=1,n;
	char ch[15];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%s",&n,ch);
		if(strcmp(ch,"Alice")==0)
		{
			if(n%3==1)
				printf("Case %ld: Bob\n",k++);
			else
				printf("Case %ld: Alice\n",k++);
		}
		else
		{
			if(n%3==1||n%3==2)
				printf("Case %ld: Bob\n",k++);
			else
				printf("Case %ld: Alice\n",k++);
		}
	}
	return 0;
}
			
