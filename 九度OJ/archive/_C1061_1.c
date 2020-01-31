#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stu
{
    char name[101];
    int grade;
    int age;
}Stu;
int cmp(const void *a,const void *b)
{
    if(((Stu *)a)->grade!=((Stu *)b)->grade)
        return ((Stu *)a)->grade-((Stu *)b)->grade;
    else if(strcmp(((Stu *)a)->name,((Stu *)b)->name)!=0)
        return strcmp(((Stu *)a)->name,((Stu *)b)->name);
    else return ((Stu *)a)->age-((Stu *)b)->age;
}
int main()
{
    int n,i;
    Stu *s;
    while(~scanf("%d",&n))
    {
        s=(Stu *)malloc(n*sizeof(Stu));
        for(i=0;i<n;i++)
            scanf("%s%d%d",s[i].name,&s[i].age,&s[i].grade);
        qsort(s,n,sizeof(Stu),cmp);
        for(i=0;i<n;i++)
            printf("%s %d %d\n",s[i].name,s[i].age,s[i].grade);
        free(s);
    }
    return 0;
}
