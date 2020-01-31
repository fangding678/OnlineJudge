#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a,b,c,d;
int len;
char ans[200];
char str[32];
void Set()
{
    len = strlen(str);
    a = b = c = d = 0;
    int i;
    for(i=0; i<len-24; ++i)
        a = a*10 + str[i] - '0';

    i = max(0, len-24);
    for(; i<len-16; ++i)
        b = b*10 + str[i] - '0';

    i = max(0, len-16);
    for(; i<len-8; ++i)
        c = c*10 + str[i] - '0';

    i = max(0, len-8);
    for(; i<len; ++i)
        d = d*10 + str[i] - '0';
}
void Cal()
{
    int ta,tb,tc,td;
    len = 0;
    while(!(a==0&&b==0&&c==0&&d==0))
    {
        ta = tb = tc = td = 0;
        if(a!=0)
        {
            ta = a%2;
            a /= 2;
        }
        if(b!=0)
        {
            tb = b%2;
            b /= 2;
            if(ta != 0)
            {
                b += 50000000;
            }
        }
        if(c!=0)
        {
            tc = c%2;
            c /= 2;
            if(tb != 0)
            {
                c += 50000000;
            }
        }
        td = d%2;
        d /= 2;
        if(tc != 0)
            d += 50000000;
        ans[len++] = '0' + td;
    }
    if(len == 0)
        ans[len++] = '0';
    ans[len] = 0;
}
void Reverse()
{
    int i=0,j=strlen(ans)-1;
    char tc;
    while(i<j)
    {
        tc = ans[i];
        ans[i] = ans[j];
        ans[j] = tc;
        i++;
        j--;
    }
}
int main()
{
    int j,k;
    while(scanf("%s",str)!=EOF)
    {
        j=0;k=0;
        len = strlen(str);
        while(str[j] == '0')
        {
            j++;
        }
        while(j<=len)
            str[k++] = str[j++];
        Set();
        Cal();
        Reverse();
        printf("%s\n",ans);
    }
    return 0;
}
