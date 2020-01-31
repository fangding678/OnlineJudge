#include<stdio.h>
int main()
{
	int n;
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		int m=1;
		if(n>6||n<1) continue;
		for(i=n;i<n+4;i++)
			for(j=n;j<n+4;j++)
				for(k=n;k<n+4;k++)
				if(i!=j&&j!=k&&i!=k)
				{
					if(m++%6!=0) printf("%d ",100*i+10*j+k);
					else printf("%d\n",100*i+10*j+k);
				}
	}
	return 0;
}
