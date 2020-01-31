#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char str1[12],str2[12];
    int ans,len1,len2;
    int i,value;
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        if(strcmp(str1, "0")==0 && strcmp(str2, "0")==0)
            break;
        ans = 0;
        value = 0;
        len1 = strlen(str1);
        len2 = strlen(str2);
        for(i=1; i<=len1 && i<=len2; ++i)
        {
            if((str1[len1-i]+str2[len2-i]+value-'0'-'0')>9)
            {
                value = 1;
                ans++;
            }
        }
        while(i<=len1)
        {
            if((str1[len1-i]+value-'0')>9)
            {
                value = 1;
                ans++;
            }
            ++i;
        }
        while(i<=len2)
        {
            if((str2[len2-i]+value-'0')>9)
            {
                value = 1;
                ans++;
            }
            ++i;
        }
        if(ans > 1)
        {
            printf("%d carry operations.\n",ans);
        }
        else if(ans == 1)
        {
            printf("%d carry operation.\n",ans);
        }
        else
        {
            printf("NO carry operation.\n");
        }
    }
    return 0;
}
