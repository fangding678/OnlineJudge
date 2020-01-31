#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,*a;
    int i,j,mid;
    int result;
    while(~scanf("%d",&n))
    {
        a = new int[n];
        for(i=0; i<n; ++i)
            scanf("%d",&a[i]);
        if(n==1)
            result = a[0];
        else if(n==2)
            result = (a[0]>a[1])?a[1]:a[0];
        else
        {
            if(a[0]>a[1])
                result = a[1];
            else if(a[n-1]<a[n-2])
                result = a[n-1];
            else
            {
                i=0, j=n-1;
                while(i<j)
                {
                    mid = (i+j)/2;
                    if(a[mid]>a[0])
                        i = mid+1;
                    else
                        j = mid;
                }
                result = (a[0]<a[i])?a[0]:a[i];
            }
        }
        printf("%d\n",result);
        delete[] a;
    }
    return 0;
}
