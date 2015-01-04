#include<stdio.h>
#include<string.h>

int main()
{
	char ch[20],re[20];
	long l,i,j,k=1,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0,j=l-1;i<l;i++,j--)
			re[i]=ch[j];
		re[i]=0;
		if(strcmp(re,ch)==0)
			printf("Case %ld: Yes\n",k++);
		else
			printf("Case %ld: No\n",k++);
	}
	return 0;
}
