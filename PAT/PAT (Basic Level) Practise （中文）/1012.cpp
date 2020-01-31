#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	int i,*a;
	int a1,a2,a3,a4,a5;
	float a_4;
	int select,flag;
	while(~scanf("%d",&N))
	{
		if(N<0||N>1000) continue;
		a=(int *)malloc(N*sizeof(int));
		a1=a2=a3=a4=a5=0;
		a_4=0.0;
		flag=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			select=a[i]%5;
			switch(select)
			{
				case 0:
					if(a[i]%2==0) a1+=a[i];
					break;
				case 1:
					if(flag%2==0) a2+=a[i];
					else a2-=a[i];
					flag++;
					break;
				case 2:
					a3++;
					break;
				case 3:
					a_4+=a[i];
					a4++;
					break;
				case 4:
					if(a[i]>a5) a5=a[i];
					break;
			}
		}
		if(a1==0) printf("N");
		else printf("%d",a1);
		if(flag==0) printf(" N");
		else printf(" %d",a2);
		if(a3==0) printf(" N");
		else printf(" %d",a3);
		if(a4==0) printf(" N");
		else printf(" %0.1f",a_4/a4);
		if(a5==0) printf(" N");
		else printf(" %d",a5);
		printf("\n");
		free(a);
	}
}
