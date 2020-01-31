#include <iostream>

using namespace std;

int n;
int ans;
bool mark[20];
int a[20];
void DFS(int sum, int i)
{
    if(sum == 40)
    {
        ans++;
        return;
    }
    if(sum > 40)
    {
        return;
    }
    for(int j=i; j<n; ++j)
    {
        if(mark[j])
            continue;
        mark[j] = true;
        DFS(sum+a[j], j+1);
        mark[j] = false;
    }
}
int main()
{
    int i;
    while(cin>>n)
    {
        for(i=0; i<n; ++i)
        {
            cin>>a[i];
            mark[i] = false;
        }
        ans = 0;
        DFS(0, 0);
        cout<<ans<<endl;
    }
    return 0;
}
