#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isHuiwen(char *s,int low,int high)
{
    while(low<high)
    {
        if(s[low]!=s[high])
            return 0;
        low++;
        high--;
    }
    return 1;
}
int main()
{
    char str[1001];
    int len;
    while(~scanf("%s",str))
    {
        len=strlen(str);
        if(isHuiwen(str,0,len-1))
            printf("Yes!\n");
        else
            printf("No!\n");
    }
    return 0;
}
