#include <iostream>
#include <algorithm>

using namespace std;
const int Max = 0x07ffffff;
int a[7][7];
bool mark[7][7];
int go[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int result;
int s2, e2;

void DFS(int s1, int e1, int sum, int status)
{
    if(s1 == s2 && e1 == e2)
    {
        result = min(result, sum);
        return ;
    }
    if(sum > result) //这一步剪枝优化十分重要。。学习网上大牛的……
        return ;
    int t,ts,te;
    for(int i=0; i<4; ++i)
    {
        ts = s1 + go[i][0];
        te = e1 + go[i][1];
        if(ts<=6&&ts>=1&&te<=6&&te>=1)
        {
            if(mark[ts][te])
                continue;
            t = sum + a[ts][te]*status;
            mark[ts][te] = true;
            DFS(ts, te, t, (a[ts][te]*status)%4+1);
            mark[ts][te] = false;
        }
    }
}
int main()
{
    int i,j,n,status;
    cin>>n;
    int s1,e1;
    while(n--)
    {
        for(i=1; i<7; ++i)
        {
            for(j=1; j<7; ++j)
            {
                cin>>a[i][j];
                mark[i][j] = false;
            }
        }
        cin>>s1>>e1>>s2>>e2;
        result = Max;
        s1++;e1++;
        s2++;e2++;
        //mark[s1][e1] = true;
        status = 1;
        DFS(s1, e1, 0, status);
        cout<<result<<endl;
    }
    return 0;
}



/*错误的做法。。题意没有理解清楚
#include <iostream>
#include <vector>

using namespace std;
const int Max = 0x07ffffff;
struct E
{
    int cost;
    int next;
};
vector<E> edge[37];
int main()
{
    int a[7][7];
    int n,i,j,t,c;
    int Min;
    int s,e,newP;
    int Dis[37];
    bool mark[37];
    cin>>n;
    while(n--)
    {
        for(i=0; i<37; ++i)
            edge[i].clear();
        for(i=1; i<7; ++i)
        {
            for(j=1; j<7; ++j)
                cin>>a[i][j];
        }
        t = 1;
        for(i=1; i<7; ++i)
        {
            for(j=1; j<7; ++j)
            {
                E tmp;
                if(i==1)
                {
                    if(j==1)
                    {
                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else if(j==6)
                    {
                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else
                    {
                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                }
                else if(i==6)
                {
                    if(j==1)
                    {
                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else if(j==6)
                    {
                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else
                    {
                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                }
                else
                {
                    if(j==1)
                    {
                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else if(j==6)
                    {
                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                    else
                    {
                        tmp.next = t+6;
                        tmp.cost = (a[i][j]*a[i+1][j])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-1;
                        tmp.cost = (a[i][j]*a[i][j-1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t+1;
                        tmp.cost = (a[i][j]*a[i][j+1])%4 + 1;
                        edge[t].push_back(tmp);

                        tmp.next = t-6;
                        tmp.cost = (a[i][j]*a[i-1][j])%4 + 1;
                        edge[t].push_back(tmp);
                    }
                }
                t++;
            }
        }
        cin>>i>>j;
        s = i*6+j+1;
        cin>>i>>j;
        e = i*6+j+1;
        //到这一步图模型已经建好了。接下来就是用Dijstra算法求解最短路径了
        for(i=1; i<37; ++i)
        {
            mark[i] = false;
            Dis[i] = -1;
        }
        Dis[s] = 0;
        mark[s] = true;
        newP = s;
        for(i=1; i<37; ++i)
        {
            for(unsigned int j=0; j<edge[newP].size(); ++j)
            {
                c = edge[newP][j].cost;
                t = edge[newP][j].next;
                if(mark[t])
                    continue;
                if(Dis[t] == -1 || Dis[t] > Dis[newP] + c)
                    Dis[t] = Dis[newP] + c;
            }
            Min = Max;
            for(int j=1; j<37; ++j)
            {
                if(mark[j])
                    continue;
                if(Dis[j] == -1)
                    continue;
                if(Min > Dis[j])
                {
                    newP = j;
                    Min = Dis[j];
                }
            }
            mark[newP] = true;
        }
        cout<<Dis[e]<<endl;
    }
    return 0;
}
*/
