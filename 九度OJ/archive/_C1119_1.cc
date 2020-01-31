#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct bigInt
{
    int digit[30];
    int cnt;
    bigInt()
    {
        cnt = 0;
        for(int i=0; i<30; ++i)
            digit[i] = 0;
    }
    void Set(string str)
    {
        int len,i,j;
        bool flag = false;
        len = str.size();
        for(i = len-1; i>=3; i-=4)
        {
            digit[cnt++] = (str[i-3]-'0')*1000 + (str[i-2]-'0')*100
            + (str[i-1]-'0')*10 + str[i]-'0';
        }
        j=0;
        while(i >= j)
        {
            flag = true;
            digit[cnt] = digit[cnt]*10 + (str[j]-'0');
            ++j;
        }
        if(flag)
            cnt++;
        for(i=cnt-1; i>=0; --i)
        {
            if(digit[i] != 0)
            {
                break;
            }
            cnt--;
        }
    }
    bigInt operator + (const bigInt & b)
    {
        bigInt sum;
        int i,value = 0;
        for(i=0; i<cnt && i<b.cnt; ++i)
        {
            sum.digit[sum.cnt++] = (digit[i] + b.digit[i] + value)%10000;
            value = (digit[i] + b.digit[i] + value)/10000;
        }
        while(i < cnt)
        {
            sum.digit[sum.cnt++] = (digit[i] + value)%10000;
            value = (digit[i] + value)/10000;
            i++;
        }
        while(i < b.cnt)
        {
            sum.digit[sum.cnt++] = (b.digit[i] + value)%10000;
            value = (b.digit[i] + value)/10000;
            i++;
        }
        if(value>0)
            sum.digit[sum.cnt++] = value;
        return sum;
    }
    void outPut()
    {
        cout<<digit[cnt-1];
        for(int i=cnt-2; i>=0; --i)
            cout<<setfill('0')<<setw(4)<<digit[i];
        cout<<endl;
    }
};
int main()
{
    string str;
    bigInt ans;
    while(cin>>str)
    {
        if(str == "0")
        {
            ans.outPut();
            break;
        }
        bigInt ta;
        ta.Set(str);
        ans = ans + ta;
    }
    return 0;
}
