#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[11];
    int len,result,i;
    while(~scanf("%s",str))
    {
        result = 0;
        len = strlen(str);
        for(i=2; i<len; ++i)
        {
            if(str[i]>='0' && str[i]<='9')
                result = result*16 + str[i]-'0';
            else if(str[i]>='A' && str[i]<='Z')
                result = result*16 + str[i] - 'A' + 10;
            else if(str[i]>='a' && str[i]<='z')
                result = result*16 + str[i] - 'a' + 10;
        }
        printf("%d\n",result);
    }
    return 0;
}
