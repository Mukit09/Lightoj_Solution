#include<stdio.h>
#include<math.h>

long i,j,a[40],t,x=1,n,m,fg,sm,k,p;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		for(i=1;i<=30;i++)
			a[i]=0;
		scanf("%ld",&n);
		m=n;
		i=1;
		while(m)
		{
			a[i]=m%2;
			m/=2;
			i++;
		}
		j=i;
		fg=1;
		for(i=j-1;i>1;i--)
		{
			if(a[i]==0&&a[i-1]==1)
			{
				fg=0;
				k=i-1;
			}
		}
		
		if(!fg)
		{
			a[k+1]=1;
			a[k]=0;
			if(n%2==0)
			{
				for(i=k-1,p=1;i>1;i--)
				{
					if(a[i]==1&&a[p]==0&&i>=p)
					{
						a[i]=0;
						a[p++]=1;
					}
				}
			}
		}
		else
		{
			j++;
			a[j-1]=0;
			fg=1;
			for(i=j-1;i>1;i--)
			{
				if(a[i]==0&&a[i-1]==1)
				{
					fg=0;
					k=i-1;
				}
			}
			
			if(!fg)
			{
				a[k+1]=1;
				a[k]=0;
				if(n%2==0)
				{
					for(i=k-1,p=1;i>1;i--)
					{
						if(a[i]==1&&a[p]==0&&i>=p)
						{
							a[i]=0;
							a[p++]=1;
						}
					}
				}
			}
		}

		sm=0;
		for(i=j-1,n=j-2;i>=1;i--,n--)
		{
			sm+=(a[i]*(pow(2,n)));
		}
		printf("Case %ld: %ld\n",x++,sm);
	}
	return 0;
}
