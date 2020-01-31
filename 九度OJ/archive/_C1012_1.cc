#include <iostream>

using namespace std;

int Tree[1001];

int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main()
{
    int n,m;
    int a,b;
    int i;
    int ans;
    while(cin>>n)
    {
        ans = 0;
        if(n == 0)
            break;
        cin>>m;
        for(i=1; i<=n; ++i)
            Tree[i] = -1;
        for(i=0; i<m; ++i)
        {
            cin>>a>>b;
            a = findRoot(a);
            b = findRoot(b);
            if(b!=a)
                Tree[a] = b;
        }
        for(i=1; i<=n; ++i)
        {
            if(Tree[i] == -1)
                ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
