#include<stdio.h>
#include<math.h>
#define M 7
int sum[10][M];
void pow_1(int m)
{
	int i,j,c;
	for(i=0;i<10;i++)
		for(j=0;j<M;j++)
			sum[i][j]=0;
	for(i=0;i<10;i++) sum[i][M-1]=pow(i,m);
	for(i=2;i<10;i++)
	{
		c=sum[i][M-1];
		for(j=M-1;j>=M-m;j--)
		{
			sum[i][j]=c%10;
			c/=10;
		}
	}
}
int main()
{
	int i,j;
	pow_1(6);
	for(i=0;i<10;i++){
		for(j=0;j<M;j++)
		printf("%d\t",sum[i][j]);
		printf("\n");
	}
	return 0;
}


