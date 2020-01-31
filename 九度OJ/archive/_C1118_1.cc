#include <iostream>
#include <string>

using namespace std;
long long aToTen(string str, int m)
{
    size_t i,len = str.size();
    long long re = 0;
    int t;
    for(i=0; i<len; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
            t = str[i] - '0';
        else if(str[i]>='a' && str[i]<='z')
            t = str[i] - 'a' + 10;
        else if(str[i]>='A' && str[i]<='Z')
            t = str[i] - 'A' + 10;
        re = re*m + t;
    }
    return re;
}
void tenToA(string &str, long long num, int m)
{
    if(num != 0)
    {
        tenToA(str, num/m, m);
        int t = num%m;
        if(t>=0 && t<=9)
            str += '0'+t;
        else
            str += 'A'+t-10;
    }
}
int main()
{
    int n,m;
    string str, ans;
    long long tresult;
    while(cin>>n>>str>>m)
    {
        tresult = aToTen(str, n);
        ans = "";
        tenToA(ans, tresult, m);
        if(ans == "") //这一步很关键，，之前就是漏掉所以AC不了……
            ans = "0";
        cout<<ans<<endl;
    }
    return 0;
}
