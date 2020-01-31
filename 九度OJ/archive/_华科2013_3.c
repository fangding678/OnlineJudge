#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isHuiwen(char *str,int low,int high)
{
    if(!isalnum(str[low])||!isalnum(str[high])) return 0;
    while(low<high)
    {
        while(!isalnum(str[low])) low++;
        while(!isalnum(str[high])) high--;
        if(low<high)
        {
            if(tolower(str[low])!=tolower(str[high]))
                return 0;
            else { low++;high--; }
        }
    }
    return 1;
}
int main()
{
    char str[1001];
    int i,j,len;
    int low,high;
    int flag;
    while(gets(str)!=NULL)
    {
        flag=0;
        len=strlen(str);
        low=high=0;
        for(i=len;i>1;i--)
        {
            for(j=len;j>i-1;j--)
            {
                if(isHuiwen(str,len-j,len-j+i-1))
                {
                    low=len-j;
                    high=len-j+i-1;
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        for(i=low;i<=high;i++)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
