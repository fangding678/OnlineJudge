#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    char str[101];
    char ans[101];
    int i,len;
    stack<int> sc;
    while(scanf("%s",str)!=EOF)
    {
        len = strlen(str);
        for(i=0; i<len; ++i)
        {
            ans[i] = ' ';
            if(str[i]=='(')
            {
                sc.push(i);
            }
            else if(str[i]==')')
            {
                if(!sc.empty())
                {
                    sc.pop();
                }
                else
                {
                    ans[i] = '?';
                }
            }
        }
        while(!sc.empty())
        {
            i = sc.top();
            sc.pop();
            ans[i] = '$';
        }
        ans[len] = 0;
        puts(str);
        puts(ans);
    }
    return 0;
}
