#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,i,j,k,min;
    int a[2001];
    while(scanf("%d",&m)!=EOF)
    {
        min=1001;
        for(i=0;i<2001;i++)
            a[i]=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&j,&k);
            a[k+1000]+=j;
            if(k<min) min=k;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&j,&k);
            a[k+1000]+=j;
            if(k<min) min=k;
        }
        for(i=2000;i>min+1000;i--)
        {
            if(a[i]!=0)
                printf("%d %d ",a[i],i-1000);
        }
        printf("%d %d\n",a[min+1000],min);
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Exp
{
    int xishu;
    int cishu;
}Exp;
int main()
{
    int m,n,i,j,k;
    Exp *a,*b,*c;
    while(scanf("%d",&m)!=EOF)
    {
        a=(Exp *)malloc(m*sizeof(Exp));
        for(i=0;i<m;i++)
            scanf("%d%d",&a[i].xishu,&a[i].cishu);
        scanf("%d",&n);
        b=(Exp *)malloc(n*sizeof(Exp));
        for(i=0;i<n;i++)
            scanf("%d%d",&b[i].xishu,&b[i].cishu);
        c=(Exp *)malloc((m+n)*sizeof(Exp));
        for(i=0,j=0,k=0;i<m&&j<n;)
        {
            if(a[i].cishu>b[j].cishu)
                c[k++]=a[i++];
            else if(a[i].cishu<b[j].cishu)
                c[k++]=b[j++];
            else
            {
                if((a[i].xishu+b[j].xishu)!=0)
                {
                    c[k].cishu=a[i].cishu;
                    c[k++].xishu=a[i++].xishu+b[j++].xishu;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }
        if(i==m&&j!=n)
            while(j!=n) c[k++]=b[j++];
        else if(i!=m&&j==n)
            while(i!=m) c[k++]=a[i++];
        if(k!=0)
        {
            for(i=0;i<k-1;i++)
                printf("%d %d ",c[i].xishu,c[i].cishu);
            printf("%d %d",c[i].xishu,c[i].cishu);
        }
        printf("\n");
        free(a);
        free(b);
        free(c);
    }
    return 0;
}
*/
