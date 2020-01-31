#include <iostream>
#include <cstdio>

using namespace std;

bool isTreeOf(int *a, int s, int e)
{
    int len = e - s + 1;
    int root = a[e];
    int i,mid;
    bool left, right;
    if(len<=2)
        return true;
    for(i=s; i<e; ++i)
    {
        if(a[i] > root)
            break;
    }
    mid = i;
    while(i<e)
    {
        if(a[i] < root)
            return false;
        i++;
    }
    left = true;
    right = true;
    if(mid > s)
        left = isTreeOf(a, s, mid-1);
    if(mid < e)
        right = isTreeOf(a, mid, e-1);
    return (left && right);
}

int main()
{
    int i, n;
    int a[10001];
    while(EOF != scanf("%d",&n))
    {
        for(i=0;i<n;++i)
            scanf("%d", &a[i]);
        if(isTreeOf(a,0,n-1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
