#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[105],ans[105];
    int len,i;
    while(gets(s) != NULL)
    {
        ans[0] = ' ';
        len = strlen(s);
        for(i=0; i<=len; ++i)
            ans[i+1] = s[i];
        for(i=0; i<len; ++i)
        {
            if((ans[i] == ' ') || (ans[i] == '\t') || (ans[i] == '\n'))
                ans[i+1] = toupper(ans[i+1]);
        }
        printf("%s\n",ans+1);
    }
    return 0;
}
