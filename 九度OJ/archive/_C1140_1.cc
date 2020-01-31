#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool mark[9][9];
int ans[100];
int cnt = 1;

bool isSafe(int deep, int m)
{
    for(int i=1; i<deep; ++i)
    {
        if(mark[m][i])
            return false;
        if(m>i && mark[m-i][deep-i])
            return false;
        if(m+i<9 && mark[m+i][deep-i])
            return false;
    }
    return true;
}
void DFS(int deep)
{
    int i,j;
    if(deep == 9)
    {
        for(j=1; j<9; ++j)
        {
            for(i=1; i<9; ++i)
            {
                if(mark[i][j])
                {
                    ans[cnt] = ans[cnt]*10 + i;
                    break;
                }
            }
        }
        cnt++;
        return ;
    }
    for(i=1; i<9; ++i)
    {
        if(isSafe(deep, i))
        {
            mark[i][deep] = true;
            DFS(deep+1);
            mark[i][deep] = false;
        }
    }
}

int main()
{
    int n,m;
    memset(mark, 0, sizeof(mark));
    memset(ans, 0, sizeof(ans));
    DFS(1);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d\n",ans[m]);
    }
    return 0;
}
