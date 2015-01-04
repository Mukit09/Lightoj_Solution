#include<stdio.h>

int main()
{
    long t,k,now,next,ans,max,min,a;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%ld%ld",&now,&next);
        if(now==next)
        {
            ans=now*4+19;
            printf("Case %ld: %ld\n",k,ans);
            continue;
        }
        else if(next>now)
        {
            max=next;
            min=now;
        }
        else
        {
            max=now;
            min=next;
        }
        a=(max-min)*4;
        ans=a+19+now*4;
        printf("Case %ld: %ld\n",k,ans);
    }
    return 0;
}
