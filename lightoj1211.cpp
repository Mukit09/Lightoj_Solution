#include<stdio.h>
#include<math.h>

int main()
{
	long t,i,n,a,b,c,x1,y1,z1,x2,y2,z2,mn_x,mn_y,mn_z,mx_x,mx_y,mx_z,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld%ld%ld%ld%ld%ld",&mn_x,&mn_y,&mn_z,&mx_x,&mx_y,&mx_z);
		for(i=2;i<=n;i++)
		{
			scanf("%ld%ld%ld%ld%ld%ld",&x1,&y1,&z1,&x2,&y2,&z2);
			if(x1>mn_x)
				mn_x=x1;
			if(y1>mn_y)
				mn_y=y1;
			if(z1>mn_z)
				mn_z=z1;
			if(x2<mx_x)
				mx_x=x2;
			if(y2<mx_y)
				mx_y=y2;
			if(z2<mx_z)
				mx_z=z2;
		}
		if(mn_x>=mx_x||mn_y>=mx_y||mn_z>=mx_z)
			printf("Case %ld: 0\n",x++);
		else
		{
			a=mx_x-mn_x;
			b=mx_y-mn_y;
			c=mx_z-mn_z;
			printf("Case %ld: %ld\n",x++,a*b*c);
		}
	}
	return 0;
}