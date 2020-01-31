#include<stdio.h>
int main()
{
	int n,i;
	int a,b,count[6];
	char s[2];
	int win,equal,fail;
	while(~scanf("%d",&n))
	{
		getchar();
		if(n<1||n>100000) continue;
		win=equal=fail=0;
		count[0]=count[1]=count[2]=count[3]=count[4]=count[5]=0;
		for(i=0;i<n;i++)
		{
			scanf("%c",&s[0]);
			getchar();
			scanf("%c",&s[1]);
			getchar();
			if(s[0]==s[1]) equal++;
			else if(s[0]=='C'&&s[1]=='J')
			{
				win++;count[0]++;
			}
			else if(s[0]=='J'&&s[1]=='B')
			{
				win++;count[1]++;
			}
			else if(s[0]=='B'&&s[1]=='C')
			{
				win++;count[2]++;
			}
			else if(s[1]=='C'&&s[0]=='J')
			{
				fail++;count[3]++;
			}
			else if(s[1]=='J'&&s[0]=='B')
			{
				fail++;count[4]++;
			}
			else
			{
				fail++;count[5]++;
			}
		}
		printf("%d %d %d\n",win,equal,fail);
		printf("%d %d %d\n",fail,equal,win);
		if(count[2]>=count[0]&&count[2]>=count[1]) printf("B ");
		else if(count[0]>count[2]&&count[0]>=count[1]) printf("C ");
		else printf("J ");
		if(count[5]>=count[3]&&count[5]>=count[4]) printf("B\n");
		else if(count[3]>count[5]&&count[3]>=count[4]) printf("C\n");
		else printf("J\n");
	}
}
