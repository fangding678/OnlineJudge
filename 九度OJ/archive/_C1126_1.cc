#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T;
    int ans[80];
    int a[80];
    int len;
    int i,j,k;
    while(cin>>T)
    {
        for(i=0; i<T; ++i)
        {
            memset(ans, -1, sizeof(ans));
            cin>>len;
            for(j=0; j<len; ++j)
            {
                cin>>a[j];
            }
            k = 0;
            if(a[0] != a[1])
                ans[k++] = 0;
            for(j=1; j<len-1; ++j)
            {
                if((a[j] > a[j-1] && a[j] > a[j+1]) ||
                   (a[j] < a[j-1] && a[j] < a[j+1]))
                    ans[k++] = j;
            }
            if(a[j-1] != a[j])
                ans[k++] = j;

            if(ans[0]!=-1)
                cout<<ans[0];
            for(j=1; ans[j]!=-1; ++j)
            {
                cout<<" "<<ans[j];
            }
            cout<<endl;
        }
    }
    return 0;
}




/*
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T;
    int ans[100][80];
    int a[100][80];
    int len[100];
    int i,j,k;
    cin>>T;
    for(i=0; i<T; ++i)
    {
        cin>>len[i];
        for(j=0; j<len[i]; ++j)
        {
            cin>>a[i][j];
        }
    }
    memset(ans, -1, sizeof(ans));
    for(i=0; i<T; ++i)
    {
        k = 0;
        if(a[i][0] != a[i][1])
            ans[i][k++] = 0;
        for(j=1; j<len[i]-1; ++j)
        {
            if((a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]) ||
               (a[i][j] < a[i][j-1] && a[i][j] < a[i][j+1]))
                ans[i][k++] = j;
        }
        if(a[i][j-1] != a[i][j])
            ans[i][k++] = j;
    }
    for(i=0; i<T; ++i)
    {
        if(ans[i][0]!=-1)
            cout<<ans[i][0];
        for(j=1; ans[i][j]!=-1; ++j)
        {
            cout<<" "<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
*/
