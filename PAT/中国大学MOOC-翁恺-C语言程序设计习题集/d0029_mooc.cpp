#include<stdio.h>
#include<malloc.h>
int main()
{
	int n,i,max;
	int *a;
	int b[10];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<10;i++) b[i]=0;
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			while(a[i]){
				b[a[i]%10]++;
				a[i]/=10;
			}
		}
		max=b[0];
		for(i=1;i<10;i++)
			if(b[i]>max) max=b[i];
		printf("%d:",max);
		for(i=0;i<10;i++) 
			if(b[i]==max) printf(" %d",i);
		printf("\n");
		free(a);
	}
	return 0;
}

/*
#include<stdio.h>
#include<malloc.h>
int main()
{
	int n,i,max;
	int *a;
	int b[10];
	scanf("%d",&n);
	for(i=0;i<10;i++) b[i]=0;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		while(a[i]){
			b[a[i]%10]++;
			a[i]/=10;
		}
	}
	max=b[0];
	for(i=1;i<10;i++)
		if(b[i]>max) max=b[i];
	printf("%d:",max);
	for(i=0;i<10;i++) 
		if(b[i]==max) printf(" %d",i);
	printf("\n");
	free(a);
	return 0;
}
*/
