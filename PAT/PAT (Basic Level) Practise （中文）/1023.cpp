#include<stdio.h>
int main()
{
	int a[10];
	int i,j,k;
	while(~scanf("%d",&a[0]))
	{
		for(i=1;i<10;i++) scanf("%d",&a[i]);
		for(k=1;k<10;k++)
			if(a[k]!=0)
			{
				printf("%d",k);
				a[k]--;
				break;
			}
		for(i=0;i<10;i++)
			for(j=0;j<a[i];j++)
				printf("%d",i);
		printf("\n");
	}
	return 0;
}
