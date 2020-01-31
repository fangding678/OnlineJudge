#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int address;
	int data;
	int next;
}Node;
void reverse(Node *a,int k,int i)
{
	int j;
	Node temp;
	for(j=i*k;j<i*k+k/2;j++)
	{
		temp=a[j];
		a[j]=a[2*k*i+k-j-1];
		a[2*k*i+k-j-1]=temp;
	}
	a[i*k+k-1].next=a[i*k+k].address;
	for(j=i*k+k-2;j>=i*k;j--)
		a[j].next=a[j+1].address;
}
int main()
{
	int add,n,k,m;
	Node *a,temp;
	int i,j,num;
		scanf("%d%d%d",&add,&n,&k);
		a=(Node *)malloc((n+1)*sizeof(Node));
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i].address,&a[i].data,&a[i].next);
		if(add==-1)
			printf("-1\n");
		a[n].address=-1;
		num=0;
		while(add!=-1)
		{
			j=num;
			while(a[j].address!=add)
				j++;
			temp=a[num];
			a[num]=a[j];
			a[j]=temp;
			add=a[num].next;
			num++;
		}
		m=num/k;
		for(i=m-1;i>=0;i--)
			reverse(a,k,i);
		for(i=0;i<num-1;i++)
			printf("%05d %d %05d\n",a[i].address,a[i].data,a[i].next);
		printf("%05d %d %d\n",a[i].address,a[i].data,a[i].next);
		free(a);
	return 0;
}

/*两个都可以提交 
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int address;
	int data;
	int next;
}Node;
void reverse(Node *a,int k,int i)
{
	int j;
	Node temp;
	for(j=i*k;j<i*k+k/2;j++)
	{
		temp=a[j];
		a[j]=a[2*k*i+k-j-1];
		a[2*k*i+k-j-1]=temp;
	}
	a[i*k+k-1].next=a[i*k+k].address;
	for(j=i*k+k-2;j>=i*k;j--)
		a[j].next=a[j+1].address;
}
int main()
{
	int add,n,k,m;
	Node *a,temp;
	int i,j,num;
	while(~scanf("%d%d%d",&add,&n,&k))
	{
		a=(Node *)malloc((n+1)*sizeof(Node));
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i].address,&a[i].data,&a[i].next);
		a[n].address=-1;
		num=0;
		while(add!=-1)
		{
			j=num;
			while(a[j].address!=add)
				j++;
			temp=a[num];
			a[num]=a[j];
			a[j]=temp;
			add=a[num].next;
			num++;
		}
		m=n/k;
		for(i=m-1;i>=0;i--)
			reverse(a,k,i);
		for(i=0;i<num-1;i++)
			printf("%05d %d %05d\n",a[i].address,a[i].data,a[i].next);
		printf("%05d %d %d\n",a[i].address,a[i].data,a[i].next);
		free(a);
	}
	return 0;
}
*/
