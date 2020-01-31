#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct E
{
    int next;
    int cost;
};
vector<E> edge[601];
int a[10001],b[10001],cost[10001],c[10001];
bool mark[601];

int main()
{
    int n,m;
    int i,j;
    int Dis[601];
    while(cin>>n && n!=0)
    {
        cin>>m;
        for(i=1; i<=n; i++)
        {
            edge[i].clear();
        }
        for(i=0; i<m; i++)
        {
            cin>>a[i]>>b[i]>>cost[i];
        }
        for(i=1; i<=n; i++)
        {
            cin>>c[i];
        }
        for(i=0; i<m; i++)
        {
            if(c[a[i]] == c[b[i]])
            {
                E tmp;
                tmp.next = b[i];
                tmp.cost = cost[i];
                edge[a[i]].push_back(tmp);
                tmp.next = a[i];
                edge[b[i]].push_back(tmp);
            }
            else if(c[a[i]] == 1)
            {
                E tmp;
                tmp.next = b[i];
                tmp.cost = cost[i];
                edge[a[i]].push_back(tmp);
            }
            else
            {
                E tmp;
                tmp.cost = cost[i];
                tmp.next = a[i];
                edge[b[i]].push_back(tmp);
            }
        }
        for(i=1; i<=n; ++i)
        {
            Dis[i] = -1;
            mark[i] = false;
        }
        int newP = 1;
        int tc,tn;
        mark[newP] = true;
        Dis[newP] = 0;
        for(i=1; i<n; ++i)
        {
            for(j=0; j<edge[newP].size(); ++j)
            {
                tn = edge[newP][j].next;
                tc = edge[newP][j].cost;
                if(mark[tn])
                    continue;
                if(Dis[tn]==-1 || Dis[tn]>Dis[newP]+tc)
                    Dis[tn] = Dis[newP]+tc;
            }
            int tmin = 0x7fffffff;
            for(j=1; j<=n; ++j)
            {
                if(mark[j] || Dis[j]==-1)
                    continue;
                if(Dis[j]<tmin)
                {
                    tmin = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        cout<<Dis[2]<<endl;
    }
    return 0;
}
