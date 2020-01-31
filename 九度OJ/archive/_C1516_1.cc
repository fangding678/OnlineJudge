#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int *a;
    int i,n;
    bool flag;
    while(~scanf("%d",&n))
    {
        if(n<=0)
            continue;
        a = new int[n];
        for(i=0; i<n; ++i)
            scanf("%d",&a[i]);
        flag = true;
        for(i=0; i<n; ++i)
        {
            if(flag && (a[i]&1)==1)
            {
                printf("%d",a[i]);
                flag = false;
                continue;
            }
            if((a[i]&1)==1)
                printf(" %d", a[i]);
        }
        for(i=0; i<n; ++i)
        {
            if(flag && (a[i]&1)==0)
            {
                printf("%d",a[i]);
                flag = false;
                continue;
            }
            if((a[i]&1)==0)
                printf(" %d", a[i]);
        }
        printf("\n");
        delete[] a;
    }
    return 0;
}


/*剑指offer中的原题解答，但是九度oj中题意不一样
#include <iostream>
#include <cstdio>

using namespace std;

bool isEven(int n)
{
    return (n&1)==0;
}

void Recorder(int *a, int n, bool (*func)(int))
{
    int bindex = 0;
    int eindex = n-1;
    while(bindex < eindex)
    {
        while(bindex < eindex && !func(a[bindex]))
            ++bindex;
        while(bindex < eindex && func(a[eindex]))
            --eindex;
        if(bindex < eindex)
        {
            int temp = a[bindex];
            a[bindex] = a[eindex];
            a[eindex] = temp;
        }
    }
}

int main()
{
    int *a;
    int i,n;
    while(~scanf("%d",&n))
    {
        if(n<=0)
            continue;
        a = new int[n];
        for(i=0; i<n; ++i)
            scanf("%d",&a[i]);
        Recorder(a, n, isEven);
        for(i=0; i<n-1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[i]);
        delete[] a;
    }
    return 0;
}
*/
