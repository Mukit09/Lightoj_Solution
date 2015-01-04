#include <stdio.h>
#include <math.h>

#define pi  (2 * acos (0.0))
#define read(f) freopen(f,"r",stdin)

int main()
{
    //read("in.txt");
    int i,test;
    double c_area,r_area,r;
    scanf("%i",&test);
    for(i = 0; i < test; ++i)
    {
        scanf("%lf",&r);
        c_area = (pi * r * r);
        r_area = (r*r)*4;
        printf("Case %i: %.2lf\n",i+1,((r_area-c_area)+.0000000001) );
    }
    return 0;
}
