#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char str[1000010];
    const int L = 1000009;
    int len;
    int index;
    while(gets(str)!=NULL)
    {
        len = strlen(str);
        index = L;
        while(len >= 0)
        {
            if(str[len]!=' ')
                str[index--] = str[len--];
            else
            {
                str[index--] = '0';
                str[index--] = '2';
                str[index--] = '%';
                len--;
            }
        }
        printf("%s\n",str+index+1);
    }
    return 0;
}
