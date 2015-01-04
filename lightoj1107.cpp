#include <stdio.h>

int main()
{
    int t,i,c,x1,y1,x2,y2,p,q;
    scanf("%i",&t);
    i = 1;
    while(t--)
    {
        //printf("Case %i: \n",i++);
        scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
        scanf("%i",&c);
        printf("Case %i:\n",i++);
        while(c--)
        {
            scanf("%i %i",&p,&q);
            if((p < x1) || (p > x2) || (q < y1) || (q > y2))
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
