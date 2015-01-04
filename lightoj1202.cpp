#include<stdio.h>
#include<math.h>

int main()
{
	long r1,c1,r2,c2,t,k=1,c;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld%ld",&r1,&c1,&r2,&c2);
		if(r1==r2&&c1==c2)
			c=0;
		else if(abs(r1-r2)==abs(c1-c2))
			c=1;
		else if(r1+c1==r2+c2)
			c=1;
		else if(((r1%2==0&&c1%2!=0)||(r1%2!=0&&c1%2==0))&&((r2%2==0&&c2%2!=0)||(r2%2!=0&&c2%2==0)))
			c=2;
		else if(((r1%2==0&&c1%2==0)||(r1%2!=0&&c1%2!=0))&&((r2%2==0&&c2%2==0)||(r2%2!=0&&c2%2!=0)))
			c=2;
		else
		{
			printf("Case %ld: impossible\n",k++);
			continue;
		}
		printf("Case %ld: %ld\n",k++,c);
	}
	return 0;
}