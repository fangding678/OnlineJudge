#include<stdio.h>
typedef struct Address
{
	char name[11];
	char brith[11];
	char sex;
	char cell[17];
	char mobile[17];
}Address;
int main()
{
	int i,n,k,t;
	Address A[10];
	while(scanf("%d",&n)!=EOF)
	{
		if(n<1||n>10) continue;
		for(i=0;i<n;i++)
		{
			//scanf("%s %s %c %s %s",A[i].name,A[i].brith,&A[i].sex,A[i].cell,A[i].mobile);
			scanf("%s%s",A[i].name,A[i].brith);
			getchar();
			scanf("%c",&A[i].sex);
			scanf("%s%s",A[i].cell,A[i].mobile);
		}
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&t);
			if(t>=0&&t<n) printf("%s %s %s %c %s\n",A[t].name,A[t].cell,A[t].mobile,A[t].sex,A[t].brith);
			else printf("Not Found\n");
		}
	}
	return 0;
}
