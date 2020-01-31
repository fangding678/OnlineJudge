#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int n;
    int i,j,len;
    int *a;
    int b[26];
    while(cin>>n)
    {
        a=new int[n];
        for(i=0;i<n;i++)
            a[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<26;j++)
                b[j]=0;
            cin>>str;
            len=str.size();
            for(j=0;j<len;j++)
            {
                b[tolower(str[j])-'a']++;
            }
            sort(b,b+26);
            for(j=25;j>=0;j--)
            {
                a[i]+=(j+1)*b[j];
            }
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<endl;
        delete []a;
    }
    return 0;
}
