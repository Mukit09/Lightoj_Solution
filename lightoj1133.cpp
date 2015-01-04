#include<stdio.h>

int main()
{
	long a[110],n,m,b[110],x;
	long i,j,k=1,y,z,t,o;
	char ch[10];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		for(x=1;x<=m;x++)
		{
			scanf("%s",&ch);
			if(ch[0]=='S')
			{
				scanf("%ld",&o);
				for(i=0;i<n;i++)
				{
					a[i]+=o;
				}
			}
			else if(ch[0]=='M')
			{
				scanf("%ld",&o);
				for(i=0;i<n;i++)
					a[i]*=o;
			}
			else if(ch[0]=='D')
			{
				scanf("%ld",&o);
				for(i=0;i<n;i++)
					a[i]/=o;
			}
			else if(ch[0]=='R')
			{
				for(i=0,j=n-1;i<n;i++,j--)
				{
					b[i]=a[j];
				}
				for(i=0;i<n;i++)
					a[i]=b[i];
			}
			else if(ch[0]=='P')
			{
				scanf("%ld%ld",&y,&z);
				o=a[y];
				a[y]=a[z];
				a[z]=o;
			}
		}
		printf("Case %ld:\n",k++);
		printf("%ld",a[0]);
		for(i=1;i<n;i++)
			printf(" %ld",a[i]);
		printf("\n");
	}
	return 0;
}