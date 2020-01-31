#include<stdio.h>
#include<malloc.h>
typedef struct Student
{
	char name[11];
	char xuehao[11];
	int score;
}Student;
int main()
{
	int n,i,max,min,x,y;
	Student *Stu;
	while(~scanf("%d",&n))
	{
		if(n<1) continue;
		Stu=(Student *)malloc(n*sizeof(Student));
		min=101;max=-1;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",Stu[i].name,Stu[i].xuehao,&Stu[i].score);
			if(Stu[i].score>max)
			{
				max=Stu[i].score;
				x=i;
			}
			if(Stu[i].score<min)
			{
				min=Stu[i].score;
				y=i;
			}
		}
		printf("%s %s\n",Stu[x].name,Stu[x].xuehao);
		printf("%s %s\n",Stu[y].name,Stu[y].xuehao);
	}
}
