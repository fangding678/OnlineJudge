#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    char str[101],ans[101];
    int len;
    while(cin>>str)
    {
        if(strcmp(str,"E") == 0)
            break;
        int a[3] = {0,0,0};
        len = strlen(str);
        while(len)
        {
            switch(str[--len])
            {
            case 'Z':
                a[0]++;
                break;
            case 'O':
                a[1]++;
                break;
            case 'J':
                a[2]++;
                break;
            default :
                break;
            }
        }
        while(a[0] || a[1] || a[2])
        {
            if(a[0])
            {
                ans[len++] = 'Z';
                a[0]--;
            }
            if(a[1])
            {
                ans[len++] = 'O';
                a[1]--;
            }
            if(a[2])
            {
                ans[len++] = 'J';
                a[2]--;
            }
        }
        ans[len] = 0;
        cout<<ans<<endl;
    }
    return 0;
}
