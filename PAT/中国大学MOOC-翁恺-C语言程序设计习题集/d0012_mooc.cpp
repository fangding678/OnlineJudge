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
	int n,i,j,k,t,m;
	int a[M],c[M];
	int d,flag;
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n<3||n>7) continue;
		m=pow(10,n-1);
		pow_1(n);
		for(i=m;i<m*10;i++)
		{
			for(j=0;j<M;j++) c[j]=a[j]=0;
			flag=1;
			t=i;
			for(j=M-1;t!=0;j--){
				a[j]=t%10;
				for(k=M-1;k>=M-n;k--)
					c[k]+=sum[a[j]][k];
				t/=10;
			}
			d=0;
			for(k=M-1;k>=0;k--){
				t=(c[k]+d)%10;
				d=(c[k]+d)/10;
				c[k]=t;
				if(a[k]!=c[k]){
					flag=0;
					break;
				}
			}
			if(flag==1){
				for(k=M-n;k<M;k++) printf("%d",a[k]);
				printf("\n");
			}
		}
	}
	return 0;
}


/*低效算法——水仙花数 
#include<stdio.h>
#include<math.h>

int main()
{
	int i,n,m,t,c,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<3||n>7) continue;
		m=pow(10,n-1);
		for(i=m;i<10*m;i++)
		{
			t=i; c=0;
			for(j=0;j<n;j++)
			{
				c+=pow(t%10,n);
				t/=10;
			}
			if(c==i) printf("%d\n",i);
		}
	}
	return 0;
}
*/

/*#include<stdio.h>
#include<math.h>
int shuixian(int sum,int n)
{
	int t=sum;
	while(t)
	{
		sum-=pow(t%10,n);
		t/=10;
	}
	if(sum==0) return 1;
	else return 0;
}
int main()
{
	int i,n,m;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<3||n>7) continue;
		m=pow(10,n-1);
		for(i=m;i<10*m;i++)
			if(shuixian(i,n)) printf("%d\n",i);
	}
	return 0;
}
*/
