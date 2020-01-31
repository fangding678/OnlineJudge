#include <stdio.h>

int gcd(int a, int b){
    int r;
    r = a%b;
    while(r){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main()
{
    int n,i;
    int a,t;
    while(~scanf("%d%d",&n,&a)){
        for(i=0;i<n;++i){
            scanf("%d",&t);
            if(a < t){
                t = gcd(t, a);
            }
            a += t;
        }
        printf("%d\n",a);
    }
    return 0;
}
