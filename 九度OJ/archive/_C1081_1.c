#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000

int main()
{
    int a0,a1,p,q,k;
    int result;
    int d[4],t[4],a[4];
    while(~scanf("%d%d%d%d%d",&a0,&a1,&p,&q,&k))
    {
        a0%=M;
        a1%=M;
        if(k==0)
            result=a0;
        else if(k==1)
            result=a1;
        else
        {
            d[0]=p%M;
            d[1]=q%M;
            d[2]=1;
            d[3]=0;
            t[0]=t[3]=1;
            t[1]=t[2]=0;
            memcpy(a,t,4*sizeof(int));
            k--;
            while(k>=1)
            {
                if((k&1)==1)
                {
                    a[0]=(t[0]*d[0]+t[1]*d[2])%M;
                    a[1]=(t[0]*d[1]+t[1]*d[3])%M;
                    a[2]=(t[2]*d[0]+t[3]*d[2])%M;
                    a[3]=(t[2]*d[1]+t[3]*d[3])%M;
                    memcpy(t,a,4*sizeof(int));
                }
                a[0]=(d[0]*d[0]+d[1]*d[2])%M;
                a[1]=(d[0]*d[1]+d[1]*d[3])%M;
                a[2]=(d[2]*d[0]+d[3]*d[2])%M;
                a[3]=(d[2]*d[1]+d[3]*d[3])%M;
                memcpy(d,a,4*sizeof(int));
                k>>=1;
            }
            result=(t[0]*a1+t[1]*a0)%M;
        }
        printf("%d\n",result);
    }
    return 0;
}

/*
int main()
{
    int a0,a1,p,q,k;
    int i,t;
    while(~scanf("%d%d%d%d%d",&a0,&a1,&p,&q,&k))
    {
        p%=M;
        q%=M;
        a0%=M;
        a1%=M;
        for(i=0;i<k;i++)
        {
            t=a1*p+a0*q;
            t%=M;
            a0=a1;
            a1=t;
        }
        printf("%d\n",a0);
    }
    return 0;
}
*/
