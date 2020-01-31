#include <iostream>
#include <vector>

using namespace std;

struct E
{
    int next;
    int d,p;
};

vector<E> G[1001];
bool mark[1001];
int Dis[1001];
int Cost[1001];

int main()
{
    int n,m;
    int a,b,d,p;
    int s,t;
    int i,j;
    E tmp;
    while(cin>>n>>m)
    {
        if(n==0 || m==0)
            break;
        for(i=1; i<=n; ++i)
        {
            G[i].clear();
            Dis[i] = -1;
            Cost[i] = -1;
            mark[i] = false;
        }
        for(i=0; i<m; ++i)
        {
            cin>>a>>b>>d>>p;
            tmp.next = b;
            tmp.d = d;
            tmp.p = p;
            G[a].push_back(tmp);
            tmp.next = a;
            G[b].push_back(tmp);
        }
        cin>>s>>t;
        Dis[s] = 0;
        Cost[s] = 0;
        mark[s] = true;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<G[s].size(); ++j)
            {
                b = G[s][j].next;
                d = G[s][j].d;
                p = G[s][j].p;
                if(mark[b] == true)
                    continue;
                if(Dis[b]==-1 || Dis[b]>d + Dis[s] ||
                   (Dis[b]==d + Dis[s] && Cost[b] > Cost[s] + p))
                {
                    Dis[b] = Dis[s] + d;
                    Cost[b] = Cost[s] + p;
                }
            }
            int mini = 200000000;
            for(j=1; j<=m; ++j)
            {
                if(mark[j] == true)
                    continue;
                if(Dis[j] == -1)
                    continue;
                if(Dis[j] < mini)
                {
                    mini = Dis[j];
                    s = j;
                }
            }
            mark[s] = true;
        }
        cout<<Dis[t]<<" "<<Cost[t]<<endl;
    }
    return 0;
}




