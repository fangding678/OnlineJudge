#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    stack<int> st;
    stack<int> sm;
    int n,t;
    char c;
    while(~scanf("%d",&n))
    {
        while(!st.empty())
            st.pop();
        while(!sm.empty())
            sm.pop();
        while(n--)
        {
            while((getchar()) != '\n');
            scanf("%c", &c);
            if(c == 's')
            {
                scanf("%d", &t);
                st.push(t);
                if(sm.empty() || sm.top()>=t)
                    sm.push(t);
                else
                    sm.push(sm.top());
                printf("%d\n",sm.top());
            }
            else if(c == 'o')
            {
                if(st.empty() || sm.empty())
                    printf("NULL\n");
                else
                {
                    st.pop();
                    sm.pop();
                    if(st.empty() || sm.empty())
                        printf("NULL\n");
                    else
                        printf("%d\n",sm.top());
                }
            }
        }
    }
    return 0;
}
