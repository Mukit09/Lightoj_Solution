
#include<stdio.h>

int main()
{
    long a,b,c,k,t,max,flag;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        flag=0;
        scanf("%ld%ld%ld",&a,&b,&c);
        if(a>b&&a>c)
        {
            max=a;
            if(a*a==b*b+c*c)
                flag=1;
        }
        else if(b>a&&b>c)
        {
            max=b;
            if(b*b==c*c+a*a)
                flag=1;
        }
        else
        {
            max=c;
            if(c*c==b*b+a*a)
                flag=1;
        }
        if(a+b+c-max>max&&flag==1)
        {
            printf("Case %ld: yes\n",k);
        }
        else
        {
            printf("Case %ld: no\n",k);
        }
    }
    return 0;
}
