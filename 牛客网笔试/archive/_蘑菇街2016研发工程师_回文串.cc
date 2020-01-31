#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isHuiWen(char *str)
{
    int len = strlen(str);
    bool ans = true;
    int i;
    for(i=0; i<len/2; ++i)
    {
        if(str[i] != str[len-1-i])
            ans = false;
    }
    return ans;
}

bool isOneHuiWen(char *str, int len)
{
    int i,j;
    char s[13];
    for(i=len; i>=0; i--)
    {
        for(j=0; j<i; ++j)
        {
            s[j] = str[j];
        }
        for(j=i+1; j<=len; ++j)
        {
            s[j] = str[j-1];
        }
        if(len == 2*i)
            s[i] = 'a';
        else
            s[i] = s[len-i];
        s[len+1] = '\0';
        if(isHuiWen(s))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char str[100];
    int len;
    while(~scanf("%s",str))
    {
        len = strlen(str);
        if(len>10)
        {
            cout<<"NO\n";
            continue;
        }
        if(isOneHuiWen(str, len))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
