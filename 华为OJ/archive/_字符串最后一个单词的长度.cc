#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[129];
    int n;
    int len;
    while(cin.getline(str,128))
    {
        n=0;
        len=strlen(str)-1;
        while(str[len]!=' '&&len>=0)
        {
            n++;
            len--;
        }
        cout<<n<<endl;
    }
    return 0;
}

/*
int main()
{
    string str;
    int n;
    int len;
    while(getline(cin,str))
    {
        n=0;
        len=str.size();
        while(str[--len]!=' ')
            n++;
        cout<<n<<endl;
    }
    return 0;
}
*/
