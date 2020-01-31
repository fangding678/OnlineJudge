#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,len,i;
    char str[81];
    while(gets(str) != NULL)
    {
        n = atoi(str);
        while(n--)
        {
            gets(str);
            len = strlen(str);
            for(i=0; i<len; ++i)
            {
                if((str[i]>='A' && str[i]<'Z') || (str[i]>='a' && str[i]<'z'))
                    str[i] = str[i] + 1;
                else if(str[i]=='z' || str[i]=='Z')
                    str[i] = str[i]-'Z'+'A';
            }
            printf("%s\n",str);
        }
    }
    return 0;
}
