#include <iostream>
#include <vector>

using namespace std;

int edge[1001][1001];

int main()
{
    int n,m;
    int a,b;
    int i,j;
    int sum;
    int result;
    while(cin>>n)
    {
        if(n == 0)
            break;
        cin>>m;
        for(i=0; i<=n; ++i)
        {
            for(j=0; j<=n; ++j)
                edge[i][j] = 0;
        }
        for(i=1; i<=m; ++i)
        {
            cin>>a>>b;
            edge[a][b] = 1;
            edge[b][a] = 1;
        }
        result = 1;
        for(i=1; i<=n; ++i)
        {
            sum = 0;
            for(j=1; j<=n; ++j)
                sum += edge[i][j];
            if(sum%2 == 1)
            {
                result = 0;
                break;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}

/*第一种做法：求解无向图中是否有回路
对题目理解出错。做法错误，原因居然是没有理解欧拉回路的概念。
题目理解错误
#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[1001];
bool mark[1001];

int DFS(int p, int pre)
{
    mark[p] = true;
    int len = edge[p].size();
    for(int i=0; i<len; ++i)
    {
        if(mark[edge[p][i]] && edge[p][i] != pre)
        {
            return 1;
        }
    }
    for(int i=0; i<len; ++i)
    {
        if(!mark[edge[p][i]])
        {
            if(DFS(edge[p][i], p))
            {
                return 1;
            }
            //mark[edge[p][i]] = false;
        }
    }
    return 0;
}

int main()
{
    int n,m;
    int a,b;
    int i;
    int result;
    while(cin>>n)
    {
        if(n == 0)
            break;
        cin>>m;
        for(i=1; i<=n; ++i)
        {
            edge[i].clear();
            mark[i] = false;
        }
        for(i=1; i<=m; ++i)
        {
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(i=1; i<=n; ++i)
        {
            if(!mark[i])
            {
                result = DFS(i, 0);
            }
            if(result)
                break;
        }
        cout<<result<<endl;
    }
    return 0;
}
*/
