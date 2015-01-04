#include<stdio.h>
#include<math.h>

int main()
{
	long t,k=1,a[5],a1[5],flag,i,n,j,sum;
	char c;
	scanf("%ld",&t);
	while(t--)
	{
		for(i=1;i<=4;i++)
		{
			scanf("%ld%c",&a[i],&c);
		}
		for(i=1;i<=4;i++)
		{

			scanf("%ld%c",&a1[i],&c);
		}

		flag=0;
		for(i=1;i<=4;i++)
		{
			sum=0;
			n=a1[i];
			j=0;
			while(n!=0)
			{
				sum=sum+(n%10)*pow(2,j);
				j++;
				n/=10;
			}
			if(sum!=a[i])
				flag=1;
		}

		if(flag)
			printf("Case %ld: No\n",k++);
		else
			printf("Case %ld: Yes\n",k++);
	}
	return 0;
}
