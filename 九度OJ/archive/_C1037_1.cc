#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int maxSize = 205;
struct bigInteger
{
    int digit[maxSize];
    int sizes;
    bool flag;
    bigInteger()
    {
        for(int i=0;i<maxSize;++i)
            digit[i] = 0;
        sizes = 0;
    }
    void setInteger(string s)
    {
        if(s[0] == '-')
            flag = true;
        else
            flag = false;
        int len = s.size();
        sizes = 0;
        int t = flag;
        for(int i=len-1; i>=t; i -= 4)
        {
            digit[sizes] = s[i] - '0';
            if(i-1 >= t)
            {
                digit[sizes] += (s[i-1] - '0')*10;
            }
            if(i-2 >= t)
            {
                digit[sizes] += (s[i-2] - '0')*100;
            }
            if(i-3 >= t)
            {
                digit[sizes] += (s[i-3] - '0')*1000;
            }
            sizes++;
        }
        while(digit[sizes-1] == 0)
            sizes--;
        if(sizes < 0)
            sizes = 0;
    }
    void opposite()
    {
        this->flag = !this->flag;
    }
    bool operator > (const bigInteger &b) const
    {
        if(sizes > b.sizes)
            return true;
        else if(sizes < b.sizes)
            return false;
        for(int i=sizes-1; i>=0; --i)
        {
            if(digit[i] > b.digit[i])
                return true;
            else if(digit[i] < b.digit[i])
                return false;
        }
        return true;
    }
    bool operator < (const bigInteger &b) const
    {
        return !(*this > b);
    }
    bool operator == (const bigInteger &b) const
    {
        if(sizes != b.sizes)
            return false;
        for(int i=sizes-1; i>=0; --i)
        {
            if(digit[i] != b.digit[i])
                return false;
        }
        return true;
    }
    bigInteger operator + (const bigInteger &b)
    {
        int sizeb = b.sizes;
        int i;
        int value = 0;
        bigInteger sum;
        for(i=0; i<sizes&&i<sizeb; ++i)
        {
            sum.digit[i] = (digit[i] + b.digit[i] + value)%10000;
            value = (digit[i] + b.digit[i] + value)/10000;
            sum.sizes++;
        }
        while(i<sizeb)
        {
            sum.digit[i] = (b.digit[i] + value)%10000;
            value = (b.digit[i] + value)/10000;
            i++;
            sum.sizes++;
        }
        while(i<sizes)
        {
            sum.digit[i] = (digit[i] + value)%10000;
            value = (digit[i] + value)/10000;
            i++;
            sum.sizes++;
        }
        sum.flag = true;
        return sum;
    }
    bigInteger operator - (const bigInteger &b)
    {
        int sizeb = b.sizes;
        int i,j;
        bigInteger sub;
        for(i=0; i<sizeb; ++i)
        {
            if(digit[i] < b.digit[i])
            {
                j = i+1;
                while(digit[j] == 0)
                {
                    digit[j] = 9999;
                    j++;
                }
                digit[j]--;
                digit[i] += 10000;
            }
            sub.digit[i] = digit[i] - b.digit[i];
            sub.sizes++;
        }
        while(i<sizes)
        {
            sub.digit[i] = digit[i];
            i++;
            sub.sizes++;
        }
        while(sub.digit[sub.sizes-1] == 0)
        {
            sub.sizes--;
        }
        return sub;
    }
    bigInteger operator * (bigInteger b)
    {
        bigInteger muilt;
        bigInteger temp;
        int sizeb = b.sizes;
        int i,j,k;
        int value;
        for(i=0; i<sizes; ++i)
        {
            value = 0;
            k = 0;
            for(j=0; j<sizeb; k++,++j)
            {
                temp.digit[k] = (b.digit[j] * digit[i] + value)%10000;
                value = (b.digit[j] * digit[i] + value)/10000;
            }
            temp.sizes = k;
            if(value != 0)
                temp.digit[temp.sizes++] = value;
            muilt = muilt + temp;
            for(j=b.sizes; j>0; --j)
            {
                b.digit[j] = b.digit[j-1];
            }
            b.digit[j] = 0;
            sizeb = ++b.sizes;
        }
        while(muilt.digit[muilt.sizes-1] == 0)
        {
            muilt.sizes--;
        }
        return muilt;
    }
    friend ostream & operator << (ostream &os, bigInteger &c)
    {
        int i;
        os<<c.digit[c.sizes-1];
        for(i=c.sizes-2; i>=0; i--)
            os<<setfill('0')<<setw(4)<<c.digit[i];
        os<<endl;
        return os;
    }
    void output()
    {
        int i;
        cout<<digit[sizes-1];
        for(i=sizes-2; i>=0; i--)
            cout<<setfill('0')<<setw(4)<<digit[i];
        cout<<endl;
    }

};


int main()
{
    char s1[405],s2[405];
    bigInteger a,b,c;
    while(cin>>s1>>s2)
    {
        a.setInteger(s1);
        b.setInteger(s2);
        if((!a.flag)&&(!b.flag))
        {
            c = a+b;
            cout<<c;

            if(a==b)
            {
                cout<<0<<endl;
            }
            else if(a>b)
            {
                c = a-b;
                cout<<c;
            }
            else
            {
                c = b-a;
                cout<<'-'<<c;
            }
            c = a*b;
            cout<<c;
        }
        else if((a.flag)&&(!b.flag))
        {
            if(a==b)
            {
                cout<<0<<endl;

                c = a+b;
                cout<<'-'<<c;
            }
            else if(a>b)
            {
                c = b+a;
                cout<<'-'<<c;

                c = a+b;
                cout<<'-'<<c;
            }
            else
            {
                c = b-a;
                cout<<c;

                c = a+b;
                cout<<'-'<<c;
            }
            c = a*b;
            cout<<'-'<<c;
        }
        else if((!a.flag)&&b.flag)
        {
            if(a==b)
            {
                cout<<0<<endl;

                c = a+b;
                cout<<c;
            }
            else if(a<b)
            {
                c = b-a;
                cout<<'-'<<c;

                c = a+b;
                cout<<c;
            }
            else
            {
                c = a-b;
                cout<<c;

                c = a+b;
                cout<<c;
            }
            c = a*b;
            cout<<'-'<<c;
        }
        else
        {
            c = a+b;
            cout<<'-'<<c;
            if(a==b)
            {
                cout<<0<<endl;
            }
            else if(a<b)
            {
                c = b-a;
                cout<<c;
            }
            else
            {
                c = a-b;
                cout<<'-'<<c;
            }
            c = a*b;
            cout<<c;
        }
    }
    return 0;
}
