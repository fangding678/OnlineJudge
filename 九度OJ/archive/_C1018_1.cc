#include <iostream>

using namespace std;

int main()
{
    int a[101];
    int i,n;
    int grade;
    while(cin>>n)
    {
        if(n == 0)
            break;
        for(i=0; i<101; ++i)
            a[i] = 0;
        for(i=0; i<n; ++i)
        {
            cin>>grade;
            ++a[grade];
        }
        cin>>i;
        cout<<a[i]<<endl;
    }
    return 0;
}
