/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
char *MyStrcat(char dstStr[],char srcStr[])
{
    int i=0,j=0;
    while(dstStr[i]!='\n')i++;
    while(srcStr[j]!='\n')
        dstStr[i++]=srcStr[j++];
    dstStr[i]='\n';
    return dstStr;
}
int main()
{
    char str1[N],str2[N];
    char *str;
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        printf("%s",str1);
        puts(str2);
        str=MyStrcat(str1,str2);
        printf("%s\n",str);
    }
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
void MyStrcat(char dstStr[],char srcStr[])
{
    int j=0,i;
    for(i=0;dstStr[i]!='\0';i++);
    while(srcStr[j]!='\0')
        dstStr[i++]=srcStr[j++];
    dstStr[i]='\0';
}
int main()
{
    char str1[N],str2[N];
    while(scanf("%s",str1)!=EOF)
    {
        getchar();
        scanf("%s",str2);
        MyStrcat(str1,str2);
        puts(str1);
    }
    return 0;
}

