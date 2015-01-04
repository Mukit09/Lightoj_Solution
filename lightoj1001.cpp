
#include<stdio.h>

int main()
{
    long i,j,n,t,k;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%ld",&n);
        for(i=0;i<=10;i++)
        {
            for(j=10;j>=0;j--)
            {
                if(i+j==n)
                    break;
            }
            if(i+j==n)
                break;
        }
        if(i<j)
            printf("%ld %ld\n",i,j);
        else
            printf("%ld %ld\n",j,i);
    }
    return 0;
}
