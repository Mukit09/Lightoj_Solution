#include<stdio.h>

int main()
{
    long long i,t,k,in,w,flag,a;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&w);
        if(w%2!=0)
        {
            printf("Case %lld: Impossible\n",k);
            continue;
        }
        in=flag=0;
        for(i=2;i<w;i+=2)
        {
            if(w%i==0)
            {
                a=w/i;
                if(a%2!=0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            printf("Case %lld: %lld %lld\n",k,a,i);
        else
            printf("Case %lld: Impossible\n",k);
    }
    return 0;
}
