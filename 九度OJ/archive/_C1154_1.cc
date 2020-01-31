#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

struct E
{
    int a,b;
    int cost;
    bool operator < (const E &A) const
    {
        return cost < A.cost;
    }
}edge[100];
int Tree[100];
int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    int tmp = findRoot(Tree[x]);
    Tree[x] = tmp;
    return tmp;
}

int main()
{
    int n,i,j,t,t2,k;
    int aa,bb,ans;
    string str;
    char c;
    while(cin>>n && n!=0)
    {
        ans = 0;
        cin.ignore();
        k=0;
        Tree[0] = -1;
        for(i=1; i<n; ++i)
        {
            Tree[i] = -1;
            cin>>c>>t;
            aa = c - 'A';
            for(j=0; j<t; ++j)
            {
                cin>>c>>t2;
                bb = c - 'A';
                edge[k].a = aa;
                edge[k].b = bb;
                edge[k].cost = t2;
                ++k;
            }
        }
        sort(edge, edge+k);
        for(i=0; i<k; ++i)
        {
            aa = findRoot(edge[i].a);
            bb = findRoot(edge[i].b);
            if(aa != bb)
            {
                Tree[aa] = bb;
                ans += edge[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
