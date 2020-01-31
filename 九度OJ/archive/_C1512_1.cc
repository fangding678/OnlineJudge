#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    stack<int> s1,s2;
    char str[10];
    int n,i,num;
    while(cin>>n)
    {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        for(i=0; i<n; ++i)
        {
            scanf("%s",str);
            if(str[1]=='U')
            {
                scanf("%d",&num);
                s1.push(num);
            }
            else
            {
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        num = s1.top();
                        s1.pop();
                        s2.push(num);
                    }
                }
                if(s2.empty())
                    printf("%d\n",-1);
                else
                {
                    printf("%d\n",s2.top());
                    s2.pop();
                }
            }
        }
    }
    return 0;
}
