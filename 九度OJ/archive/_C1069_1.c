#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char xuehao[100];
    char name[100];
    char sex[3];
    int age;
}Student;
void Search(Student *s,int n,char *t)
{
    int i,flag=0;
    for(i=0;i<n;i++)
        if(strcmp(s[i].xuehao,t)==0)
        {
            flag=1;
            printf("%s %s %s %d\n",s[i].xuehao,s[i].name,s[i].sex,s[i].age);
            break;
        }
    if(flag==0)
        printf("No Answer!\n");
}
int main()
{
    int i,n,m;
    Student Stu[1000];
    char a[10000][100];
    while(~scanf("%d",&n))
    {
        if(n<1||n>1000)
            continue;
        for(i=0;i<n;i++)
            scanf("%s%s%s%d",Stu[i].xuehao,Stu[i].name,Stu[i].sex,&Stu[i].age);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%s",a[i]);
        for(i=0;i<m;i++)
            Search(Stu,n,a[i]);
    }
    return 0;
}
