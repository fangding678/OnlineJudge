#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x0,y0,z0,x1,y1,z1,r,v;
    double IP;
    IP=acos(-1);
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&z0,&x1,&y1,&z1))
    {
        r=sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)+(z1-z0)*(z1-z0));
        v=4*IP*r*((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)+(z1-z0)*(z1-z0))/3;
        printf("%0.3lf %0.3lf\n",r,v);
    }
    return 0;
}
