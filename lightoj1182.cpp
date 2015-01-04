#include<stdio.h>

int main()
{
    long n,t,k,a[100],c,i;
    scanf("%ld",&t);
    for(k=1;k<=t;k++)
    {
        c=0;
        scanf("%ld",&n);
        i=1;
        while(n)
        {
            a[i]=n%2;
            n/=2;
            if(a[i]==1)
                c++;
            i++;
        }
        if(c%2==0)
            printf("Case %ld: even\n",k);
        else
            printf("Case %ld: odd\n",k);
    }
    return 0;
}
