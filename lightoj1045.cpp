#include<stdio.h>
#include<math.h>

#define size 1000005

double a[size],d[size];

int main()
{
	long t,k=1,n,b,i;
	double c;
	for(i=1;i<size;i++)
	{
		a[i]=a[i-1]+log10(i);
		d[i]=d[i-1]+log(i);
	}

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&b);

		if(b==10)
		{
			c=floor(a[n])+1;
			printf("Case %ld: %.0lf\n",k++,c);
		}
		else
		{
			c=floor(d[n]/log(b))+1;			
			printf("Case %ld: %.0lf\n",k++,c);
		}
	}
	return 0;
}