#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employ
{
    int hao;
    char s[11];
    int age;
}Employ;
int cmp(const void *a,const void *b)
{
    if(((Employ *)a)->age>((Employ *)b)->age)
        return 1;
    else if(((Employ *)a)->age==((Employ *)b)->age)
    {
        if(((Employ *)a)->hao>((Employ *)b)->hao)
            return 1;
        else if(((Employ *)a)->hao==((Employ *)b)->hao)
        {
            if(strcmp(((Employ *)a)->s,((Employ *)b)->s)>0)
                return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}
int main()
{
    int n,i;
    Employ *a;
    while(~scanf("%d",&n))
    {
        a=(Employ *)malloc(n*sizeof(Employ));
        for(i=0;i<n;i++)
            scanf("%d%s%d",&a[i].hao,a[i].s,&a[i].age);
        qsort(a,n,sizeof(Employ),cmp);
        if(n>3) n=3;
        for(i=0;i<n;i++)
            printf("%d %s %d\n",a[i].hao,a[i].s,a[i].age);
        free(a);
    }
    return 0;
}
