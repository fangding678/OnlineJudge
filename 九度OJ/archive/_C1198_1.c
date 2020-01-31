#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1010],str1[1010],str2[1010];
    int i,j,value;
    int len1,len2;
    while(~scanf("%s%s",str1,str2))
    {
        len1=strlen(str1);
        len2=strlen(str2);
        i=0;
        value=0;
        while(len1&&len2)
        {
            value+=(str1[len1-1]-'0'+str2[len2-1]-'0');
            str[i]=value%10+'0';
            value/=10;
            i++;
            len1--;
            len2--;
        }
        if(len1==0)
        {
            while(len2)
            {
                value+=(str2[len2-1]-'0');
                str[i]=value%10+'0';
                value/=10;
                len2--;
                i++;
            }
        }
        else
        {
            while(len1)
            {
                value+=(str1[len1-1]-'0');
                str[i]=value%10+'0';
                value/=10;
                len1--;
                i++;
            }
        }
        if(value>0) printf("%d",value);
        for(j=i-1;j>=0;j--)
            printf("%c",str[j]);
        printf("\n");
    }
    return 0;
}
