#include<stdio.h>
int main()
{
	char s[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[61],str2[61],str3[61],str4[61];
	int i,flag,h;
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s%s%s",str2,str3,str4);
		i=0;
		while(!(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G')) i++;
		flag=str1[i]-'A';
		i++;
		while(!(str1[i]==str2[i]&&((str1[i]>='A'&&str1[i]<='N')||(str1[i]>='0'&&str1[i]<='9')))) i++;
		if(str1[i]>='0'&&str1[i]<='9') h=str1[i]-'0';
		else if(str1[i]>='A'&&str1[i]<='N') h=str1[i]-'A'+10;
		for(i=0;str3[i]!='\0',str4[i]!='\0';i++)
			if(str3[i]==str4[i]&&((str3[i]>='a'&&str3[i]<='z')||(str3[i]>='A'&&str3[i]<='Z')))
				break;
		printf("%s %02d:%02d",s[flag],h,i);
	}
	return 0;
}
