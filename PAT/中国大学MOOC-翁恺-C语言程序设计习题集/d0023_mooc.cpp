/*
#include<stdio.h>
#define N 100
int main()
{
	int i=0,n=0,flag=0;
	char str[N];
	do{
		scanf("%c",&str[i]);
		i++;
	}while(str[i-1]!='.');
	for(i=0;str[i]!='.';i++)
	{
		if(str[i]==' '&&flag==1){
			if(n>0) printf(" %d",n);
			n=-1;
		}
		if(str[i]==' '&&flag==0){
			if(n>0){
				printf("%d",n);
				n=-1;
				flag=1;
			}
			if(str[i+1]==' ') n=-2;
		}
		n++;
	}
	if(n>0) printf(" %d",n);
	printf("\n");
	return 0;
}
*/


#include<stdio.h>
#define N 100
int main()
{
	int i,n,flag,flag2;
	char str[N];
	while(gets(str)!=NULL)
	{
		n=0; flag=0;flag2=0;
		for(i=0;str[i]!='.';i++)
		{
			if(str[i]==' '&&flag==1){
				if(n>0) printf(" %d",n);
				n=-1;
			}
			if(str[i]==' '&&flag==0){
				if(n>0){
					printf("%d",n);
					n=-1;
					flag=1;
					flag2=1;
				}
				if(str[i+1]==' ') n=-2; 
			}
			n++;
		}
		if(n>0){
			if(flag2==1)printf(" ");
			printf("%d",n);
		}
		printf("\n");
	}
	return 0;
}

