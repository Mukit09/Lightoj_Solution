
#include<stdio.h>

int main()
{
long a,b,t,i;
scanf("%ld",&t);
for(i=1;i<=t;i++)
{
scanf("%ld%ld",&a,&b);
printf("Case %ld: %ld\n",i,a+b);
}
return 0;
}
