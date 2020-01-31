#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct BiTNode
{
    int data;
    int index;
    int leftnode,rightnode;
};

void createTree(BiTNode *T, int n)
{
    int i,t;
    for(i=1; i<=n; ++i)
    {
        scanf("%d%d%d",&T[i].data, &T[i].leftnode, &T[i].rightnode);
        if(T[i].leftnode > T[i].rightnode)
        {
            t = T[i].leftnode;
            T[i].leftnode = T[i].rightnode;
            T[i].rightnode = t;
        }
        T[i].index = i;
    }
}

void resultPrint(BiTNode *T, int ind, vector<int> &v, int cursum, int sum)
{
    cursum += T[ind].data;
    v.push_back(T[ind].index);
    bool isLeaf = (T[ind].leftnode==-1) && (T[ind].rightnode==-1);
    if(cursum == sum && isLeaf)
    {
        printf("A path is found:");
        vector<int>::iterator iter = v.begin();
        for(; iter!=v.end(); ++iter)
            printf(" %d", *iter);
        printf("\n");
    }
    if(T[ind].leftnode != -1)
        resultPrint(T, T[ind].leftnode, v, cursum, sum);
    if(T[ind].rightnode != -1)
        resultPrint(T, T[ind].rightnode, v, cursum, sum);
    v.pop_back();
}

int main()
{
    BiTNode T[10001];
    int n,sum;
    vector<int> v;
    while(~scanf("%d%d",&n,&sum))
    {
        createTree(T, n);
        printf("result:\n");
        resultPrint(T, 1, v, 0, sum);
        v.clear();
    }
    return 0;
}
