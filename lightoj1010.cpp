#include<stdio.h>

int main()
{
    long t,k,n,r,c,a,b;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%ld%ld",&r,&c);
        if(r==1||c==1)
        {
            n=r*c;
        }
        else if(r==2)
        {
            a=c/4;
            b=c%4;
            if(b==3)
            {
                b=2;
            }
            n=4*a+b*2;
        }
        else if(c==2)
        {
            a=r/4;
            b=r%4;
            if(b==3)
            {
                b=2;
            }
            n=4*a+b*2;
        }
        else if(c*r%2==0)
        {
            n=(c*r)/2;
        }
        else if(r*c%2!=0)
        {
            n=(c*r)/2+1;
        }
        printf("Case %ld: %ld\n",k,n);
    }
    return 0;
}
