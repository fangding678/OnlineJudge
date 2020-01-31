#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int curadd;
	int data;
	int nextadd;
}Node;
int main()
{
	int n,k,firstadd,i,num,j;
	Node *a,temp;
	int c;
	while(scanf("%d%d%d",&firstadd,&n,&k)!=EOF)
	{
		a=(Node *)malloc(n*sizeof(Node));
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i].curadd,&a[i].data,&a[i].nextadd);
		num=0;
		while(firstadd!=-1)
		{
			j=num;
			while(a[j].curadd!=firstadd)
				j++;
			firstadd=a[j].nextadd;
			temp=a[num];
			a[num]=a[j];
			a[j]=temp;
			num++;
		}
		if(k>num)
		{
			for(i=0;i<num-1;i++)
				printf("%05d %d %05d\n",a[i].curadd,a[i].data,a[i+1].curadd);
			printf("%05d %d -1\n",a[i].curadd,a[i].data);
		}
		else if(k==num)
		{
			for(i=num-1;i>0;i--)
				printf("%05d %d %05d\n",a[i].curadd,a[i].data,a[i-1].curadd);
			printf("%05d %d -1\n",a[0].curadd,a[0].data);
		}
		else
		{
			c=num/k;
			for(i=0;i<c;i++)
			{
				for(j=0;j<k/2;j++)
				{
					temp=a[k*i+j];
					a[k*i+j]=a[k*i+k-j-1];
					a[k*i+k-j-1]=temp;
				}
			}
			for(i=0;i<num-1;i++)
				printf("%05d %d %05d\n",a[i].curadd,a[i].data,a[i+1].curadd);
			printf("%05d %d -1\n",a[i].curadd,a[i].data);
		}
	}
	return 0;
}
