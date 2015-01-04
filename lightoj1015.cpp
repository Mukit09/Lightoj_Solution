#include <stdio.h>

int main()
{
    int a,n,sum,i,j,test;
    scanf("%i",&test);
    for(i = 0; i < test; ++i)
    {
        sum =0;
        scanf("%i",&n);
        for(j = 1; j <= n; j++)
        {
            scanf("%i",&a);
            if (a < 0)
                a = 0;
            sum = sum+a;
        }
        printf("Case %i: %i\n",(i+1),sum);

    }
    return 0;
}
