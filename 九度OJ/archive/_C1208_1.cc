#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct bigInt
{
    char digit[1001];
    int len1;
    bigInt()
    {
        len1 = 0;
        memset(digit,0,sizeof(digit));
    }
    void Set(char *st)
    {
        strcpy(digit,st);
        len1 = strlen(digit);
    }
    bool operator % (int i) const
    {
        if(len1==0)
            return false;
        return (digit[0]-'0')%i;
    }
    bigInt operator / (int number)
    {
        bigInt b;
        int i,t;
        int value = 0;
        b.len1 = len1;
        if((digit[len1-1]-'0'+value)<2)
        {
            b.len1--;
        }
        for(i=len1-1; i>=0; --i)
        {
            t = digit[i]-'0'+10*value;
            b.digit[i] = t/number + '0';
            value = t%number;
        }
        b.digit[b.len1] = 0;
        return b;
    }
    bigInt operator * (const int number)
    {
        int value = 0;
        int i,t;
        bigInt b;
        for(i=0; i<len1; ++i)
        {
            t = (digit[i]-'0')*number+value;
            b.digit[b.len1++] = t%10 + '0';
            value = t/10;
        }
        if(value > 0)
            b.digit[b.len1++] = value + '0';
        b.digit[b.len1] = 0;
        return b;
    }
    bigInt operator ++()
    {
        int value = 1;
        for(int i=0; i<this->len1; ++i)
        {
            this->digit[i] = (this->digit[i]-'0'+value)%10+'0';
            value = (this->digit[i]-'0'+value)/10;
            if(value==0)
                break;
        }
        if(value>0)
            this->digit[len1++] = value + '0';
        return *this;
    }
    void PrintEight()
    {
        for(int i=len1-1; i>=0; i--)
            cout<<digit[i];
        cout<<endl;
    }
};

int main()
{
    char str[1002];
    char st[4000];
    char c;
    int len,i,j;
    int ll;
    bigInt a;
    while(cin>>str)
    {
        len = strlen(str);
        i=0;j=len-1;
        while(i<j)
        {
            c = str[i];
            str[i] = str[j];
            str[j] = c;
            i++;
            j--;
        }
        while(str[len-1]=='0')
            len--;
        str[len] = 0;
        if((len==1 && str[0]=='0')||len==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        a.Set(str);
        bigInt b;
        ll = 0;
        while(a.len1)
        {
            if(a%2)
                st[ll] = '1';
            else
                st[ll] = '0';
            ll++;
            b = a/2;
            a = b;
        }
        st[ll] = 0;
        bigInt cc,d;
        char ss[2] = "1";
        cc.Set(ss);
        i=0; j=ll-1;
        while(i<j)
        {
            c = st[i];
            st[i] = st[j];
            st[j] = c;
            i++;
            j--;
        }
        while(st[ll-1]=='0')
            ll--;
        for(i=ll-2; i>=0; --i)
        {
            d = cc*2;
            if(st[i] == '1')
                ++d;
            cc = d;
            //cc.PrintEight();
        }
        cc.PrintEight();
    }
    return 0;
}
