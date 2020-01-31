#include <stdio.h>
#include <stdlib.h>
typedef struct Stu
{
    int hao;
    int grade;
}Stu;
int cmp(const void *a,const void *b)
{
    if(((Stu *)a)->grade!=((Stu *)b)->grade)
        return ((Stu *)a)->grade - ((Stu *)b)->grade;
    else
        return ((Stu *)a)->hao - ((Stu *)b)->hao;
}
int main()
{
    int i,n;
    Stu *s;
    while(~scanf("%d",&n))
    {
        if(n<1||n>100) continue;
        s=(Stu *)malloc(n*sizeof(Stu));
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].hao,&s[i].grade);
        qsort(s,n,sizeof(Stu),cmp);
        for(i=0;i<n;i++)
            printf("%d %d\n",s[i].hao,s[i].grade);
        free(s);
    }
    return 0;
}
