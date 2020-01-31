#include <iostream>
#include <string>

using namespace std;

int a[15] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
string str[15] = {"2(0)","2","2(2)","2(2+2(0))","2(2(2))","2(2(2)+2(0))","2(2(2)+2)",
    "2(2(2)+2+2(0))","2(2(2+2(0)))","2(2(2+2(0))+2(0))","2(2(2+2(0))+2)","2(2(2+2(0))+2+2(0))",
    "2(2(2+2(0))+2(2))","2(2(2+2(0))+2(2)+2(0))","2(2(2+2(0))+2(2)+2)"};
bool flag;
void expone(int n)
{
    for(int i=14; i>=0; i--)
    {
        if(n<a[i])
            continue;
        else
        {
            if(flag)
            {
                cout<<"+"<<str[i];
            }
            else
            {
                flag = true;
                cout<<str[i];
            }
            n -= a[i];
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        flag = false;
        expone(n);
        cout<<endl;
    }
    return 0;
}
