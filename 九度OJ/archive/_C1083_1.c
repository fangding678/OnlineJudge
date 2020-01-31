#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[11],str2[11];
    int ans,i,j;
    while(~scanf("%s%s",str1,str2))
    {
        i=0;
        ans=0;
        while(str1[i]!='\0')
        {
            j=0;
            while(str2[j]!='\0')
            {
                ans+=(str1[i]-'0')*(str2[j]-'0');
                j++;
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
