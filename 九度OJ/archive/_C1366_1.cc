#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

bool isPopOrder(const int *a, const int *b, int n)
{
    stack<int> st;
    int i,j;
    st.push(a[0]);
    for(i=1,j=0; j<n; ++j)
    {
        if(st.empty())
            st.push(a[i++]);
        while(b[j] != st.top())
        {
            if(i == n)
                return false;
            st.push(a[i++]);
        }
        st.pop();
    }
    return true;
}

int main()
{
    int n,i;
    int *a,*b;
    while(EOF != scanf("%d", &n))
    {
        a = new int[n];
        b = new int[n];
        for(i=0; i<n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for(i=0; i<n; ++i)
        {
            scanf("%d", &b[i]);
        }
        if(isPopOrder(a,b,n))
            printf("Yes\n");
        else
            printf("No\n");
        delete b;
        delete a;
    }
    return 0;
}
