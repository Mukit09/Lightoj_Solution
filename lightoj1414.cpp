#include<stdio.h>
#include<string.h>

int main()
{
	char mon1[20],mon2[20],c;
	long  d1,d2,y1,y2,count,t,k=1,i,f,la,d,flag;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s%ld%c%ld",mon1,&d1,&c,&y1);
		scanf("%s%ld%c%ld",mon2,&d2,&c,&y2);

		if(y1==y2)
		{
			if(strcmp(mon2,"January")==0)
			{
				printf("Case %ld: 0\n",k++);
				continue;
			}
			else if(strcmp(mon2,"February")==0&&d2<29)
			{
				printf("Case %ld: 0\n",k++);
				continue;
			}
		}

		flag=count=0;
		f=y1;
		la=y2;
		for(i=y1;i<=y2;i++)
		{
			if(((i%4==0&&i%100!=0)||i%400==0)&&i==y1)
			{
				if(strcmp(mon1,"January")==0||strcmp(mon1,"February")==0)
				{
					flag=1;
					count++;
					f=i;
					break;
				}
			}
			else if(((i%4==0&&i%100!=0)||i%400==0)&&i==y2)
			{
				if((strcmp(mon2,"January")==0)||(strcmp(mon2,"February")==0&&d2<29))
					continue;
				else 
				{
					flag=1;
					count++;
					f=i;
					break;
				}
			}
			else if((i%4==0&&i%100!=0)||i%400==0)
			{
				flag=1;
				f=i;
				count++;
				break;
			}
		}
		for(i=y2;i>=y1;i--)
		{
			if(((i%4==0&&i%100!=0)||i%400==0)&&i==y2)
			{
				la=i;
				if(strcmp(mon2,"January")==0)
				{
					continue;
				}
				else if(strcmp(mon2,"February")==0&&d2<29)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else if(((i%4==0&&i%100!=0)||i%400==0)&&i==y1)
			{
				if(strcmp(mon1,"January")==0||strcmp(mon1,"February")==0)
				{
					la=i;
					break;
				}
			}
			else if((i%4==0&&i%100!=0)||i%400==0)
			{
				la=i;
				break;
			}
		}
		if(flag)
		{
			d=la-f;
			count+=d/4;
			count-=d/100;
			count+=d/400;
		}
		printf("Case %ld: %ld\n",k++,count);
	}
	return 0;
}