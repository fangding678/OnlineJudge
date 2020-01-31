/*#include<stdio.h>
int main()
{
	int m,n,i,c;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c);
		if(c>m) printf("Too big\n");
		if(c<m&&c>=0) printf("Too small\n");
		if(c<0){
			printf("Game Over\n");
			break;
		}
		if(i==n&&c!=m) printf("Game Over\n");
		if(c==m)
		{
			if(i==1) printf("Bingo!\n");
			if(i==2||i==3) printf("Lucky You!\n");
			if(i>3) printf("Good Guess!\n");
			break;
		}
	}
	return 0;
}*/



#include<stdio.h>
int main()
{
	int m,n,i,c;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m<1||n<1||m>100||n>100) continue;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c);
			if(c>m) printf("Too big\n");
			if(c==m)
			{
				if(i==1) printf("Bingo!\n");
				if(i==2||i==3) printf("Lucky You!\n");
				if(i>3) printf("Good Guess!\n");
				break;
			}
			if(c>=0&&c<m) printf("Too small\n");
			if(c<0){
				printf("Game Over\n");
				break;
			}
			if(c!=m&&i==n) printf("Game Over\n");
		}
	}
	return 0;
}

