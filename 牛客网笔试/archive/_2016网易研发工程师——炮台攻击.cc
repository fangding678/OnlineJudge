#include <iostream>
#include <cstdio>

using namespace std;

struct P
{
    int x;
    int y;
    int Dis(P &b)
    {
        return (((this->x - b.x)*(this->x - b.x))+((this->y - b.y)*(this->y - b.y)));
    }
};

int main()
{
    int R, num;
    P p1,p2,p3,p;
    while(~scanf("%d%d%d%d%d%d%d%d%d",&R,&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p.x,&p.y))
    {
        num = 0;
        R *= R;
        if(p1.Dis(p) <= R)
            ++num;
        if(p2.Dis(p) <= R)
            ++num;
        if(p3.Dis(p) <= R)
            ++num;
        printf("%dx\n",num);
    }
    return 0;
}
