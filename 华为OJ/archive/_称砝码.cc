#include <iostream>
#include <set>

using namespace std;

int fama(int n, int* w, int* nums)
{
    set<int> iset;
    int i,j;
    int sum=0;
    set<int>::iterator iter;
    for(i=0;i<n;i++)
        sum+=w[i]*nums[i];
    iset.insert(sum);
    for(i=0;i<n;++i)
    {
        iter=iset.begin();
        while(iter!=iset.end())
        {
            for(j=0;j<=nums[i];j++)
                iset.insert(*iter-j*w[i]);
            ++iter;
        }
    }

    return iset.size();
}

int main()
{
    int n,i;
    int *w,*num;
    while(cin>>n)
    {
        w=new int[n];
        for(i=0;i<n;i++)
            cin>>w[i];
        num=new int[n];
        for(i=0;i<n;i++)
            cin>>num[i];
        cout<<fama(n,w,num)<<endl;
        delete [] w;
        delete [] num;
    }
    return 0;
}
