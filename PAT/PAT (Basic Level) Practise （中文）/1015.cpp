#include<stdio.h>
#include<stdlib.h>
typedef struct Stu
{
	int xuehao;
	int score_d;
	int score_c;
	int flag;
}Stu;
int cmp1(const void *a,const void *b)
{
	if( (((Stu *)a)->score_d+((Stu *)a)->score_c<(((Stu *)b)->score_d+((Stu *)b)->score_c)) )
		return 1;
	else if( (((Stu *)a)->score_d+((Stu *)a)->score_c==(((Stu *)b)->score_d+((Stu *)b)->score_c)) )
	{
		if( ((Stu *)a)->score_d<((Stu *)b)->score_d )
			return 1;
		else if( ((Stu *)a)->score_d==((Stu *)b)->score_d )
		{
			if( ((Stu *)a)->xuehao>((Stu *)b)->xuehao )
				return 1;
			else return -1;
		}
		else return -1;
	}
	else return -1;
}
int main()
{
	int n,l,h;
	Stu *stu,*stu1;
	int i,j,n1,n2,n3,n4;
	while(~scanf("%d%d%d",&n,&l,&h))
	{
		stu=(Stu *)malloc(n*sizeof(Stu));
		for(i=0;i<n;i++)
			scanf("%d%d%d",&stu[i].xuehao,&stu[i].score_d,&stu[i].score_c);
		stu1=(Stu *)malloc(n*sizeof(Stu));
		j=0;
		for(i=0;i<n;i++)
		{
			if(stu[i].score_d>=h&&stu[i].score_c>=h){
				stu[i].flag=1;
				stu1[j]=stu[i];
				j++;
			}
		}
		n1=j;
		for(i=0;i<n;i++)
		{
			if(stu[i].score_d>=h&&stu[i].score_c>=l&&stu[i].flag!=1){
				stu[i].flag=1;
				stu1[j]=stu[i];
				j++;
			}
		}
		n2=j;
		for(i=0;i<n;i++)
		{
			if(stu[i].flag!=1&&stu[i].score_d>=stu[i].score_c&&stu[i].score_d>=l&&stu[i].score_c>=l){
				stu[i].flag=1;
				stu1[j]=stu[i];
				j++;
			}
		}
		n3=j;
		for(i=0;i<n;i++)
		{
			if(stu[i].flag!=1&&stu[i].score_d>=l&&stu[i].score_c>=l){
				stu[i].flag=1;
				stu1[j]=stu[i];
				j++;
			}
		}
		n4=j;
		qsort(stu1,n1,sizeof(stu1[0]),cmp1);
		qsort(&stu1[n1],n2-n1,sizeof(stu1[0]),cmp1);
		qsort(&stu1[n2],n3-n2,sizeof(stu1[0]),cmp1);
		qsort(&stu1[n3],n4-n3,sizeof(stu1[0]),cmp1);
		printf("%d\n",n4);
		for(i=0;i<n4;i++)
			printf("%d %d %d\n",stu1[i].xuehao,stu1[i].score_d,stu1[i].score_c);
	}
}
