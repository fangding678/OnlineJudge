#include<stdio.h>
int main()
{
	int x,y,z;
	int n,i,j;
	char str[101];
	while(~scanf("%d",&n))
	{
		if(n<0||n>=10) continue;
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			x=y=z=0;j=0;
			while(str[j]=='A') {
				x++; j++;
			}
			if(str[j++]!='P'){
				printf("NO\n");
				continue;
			}
			while(str[j]=='A'){
				y++; j++;
			}
			if(str[j++]!='T'){
				printf("NO\n");
				continue;
			}
			while(str[j]=='A'){
				z++;j++;
			}
			if(str[j]!='\0'){
				printf("NO\n");
				continue;
			}
			if(x*y!=z||y==0) printf("NO\n");
			else printf("YES\n");
		}
	}
}
