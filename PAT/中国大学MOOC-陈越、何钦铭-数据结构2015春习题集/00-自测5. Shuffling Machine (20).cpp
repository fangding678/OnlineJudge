#include<stdio.h>
int main()
{
	int a[55];
	int t[55],c[55];
	int i,n;
	scanf("%d",&n);
		for(i=1;i<55;i++)
			scanf("%d",&t[i]);
		for(i=1;i<55;i++)
			a[i]=i;
		while(n--)
		{
			for(i=1;i<55;i++)
				c[t[i]]=a[i];
			for(i=1;i<55;i++)
				a[i]=c[i];
		}
		if(a[1]<=13) printf("S%d",a[1]);
		else if(a[1]<=26) printf("H%d",a[1]-13);
		else if(a[1]<=39) printf("C%d",a[1]-26);
		else if(a[1]<=52) printf("D%d",a[1]-39);
		else printf("J%d",a[1]-52);
		for(i=2;i<55;i++)
		{
			if(a[i]<=13) printf(" S%d",a[i]);
			else if(a[i]<=26) printf(" H%d",a[i]-13);
			else if(a[i]<=39) printf(" C%d",a[i]-26);
			else if(a[i]<=52) printf(" D%d",a[i]-39);
			else printf(" J%d",a[i]-52);
		}
		printf("\n");
	return 0;
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
	int a[54];//{36,52,37,38,3,39,40,53,54,41,11,12,13,42,43,44,2,4,23,24,25,26,27,6,7,8,48,49,50,51,9,10,14,15,16,5,17,18,19,1,20,21,22,28,29,30,31,32,33,34,35,45,46,47};
	int t[54],c[54];
	int i,n;
	while(~scanf("%d",&n))
	{
		for(i=0;i<54;i++)
			scanf("%d",&a[i]);
		for(i=0;i<54;i++)
			t[i]=a[i];
		while(n--)
		{
			//memcpy(t,a,sizeof(a));
			for(i=0;i<54;i++)
				c[t[i]-1]=a[i];
			for(i=0;i<54;i++)
				a[i]=c[i];
		}
		if(a[0]<=13) printf("S%d",a[0]);
		else if(a[0]<=26) printf("H%d",a[0]-13);
		else if(a[0]<=39) printf("C%d",a[0]-26);
		else if(a[0]<=52) printf("D%d",a[0]-39);
		else printf("J%d",a[0]-52);
		for(i=1;i<54;i++)
		{
			if(a[i]<=13) printf(" S%d",a[i]);
			else if(a[i]<=26) printf(" H%d",a[i]-13);
			else if(a[i]<=39) printf(" C%d",a[i]-26);
			else if(a[i]<=52) printf(" D%d",a[i]-39);
			else printf(" J%d",a[i]-52);
		}
		printf("\n");
	}
	return 0;
}
*/
