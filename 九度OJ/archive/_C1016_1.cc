#include <iostream>
#include <string>

using namespace std;

const int N = 26;
int prime[N];
bool mark[121];
void getPrime()
{
    int i,j;
    for(i=1; i<121; ++i)
        mark[i] = false;
    for(i=2; i<=11; ++i)
    {
        for(j=2*i; j<=121; j+=i)
        {
            mark[j] = true;
        }
    }
    j=0;
    for(i=2; i<121; ++i)
    {
        if(mark[i] == false)
            prime[j++] = i;
        if(j == N)
            break;
    }
}

int main()
{
    string sa,sb;
    int a[N],b[N],c[N];
    int i,j,k1,k2;
    int tt,t;
    int lena,lenb;
    int value;
    getPrime();
    while(cin>>sa>>sb)
    {
        if(sa == "0" && sb == "0")
            break;

        for(i=0; i<N; ++i)
            a[i] = b[i] = c[i] = 0;
        lena = sa.size();
        lenb = sb.size();
        k1 = 0;
        for(i=0; i<lena; ++i)
        {
            if(sa[i] == ',')
            {
                k1++;
                continue;
            }
            t = sa[i] - '0';
            a[k1] = a[k1]*10 + t;
        }
        k2 = 0;
        for(i=0; i<lenb; ++i)
        {
            if(sb[i] == ',')
            {
                k2++;
                continue;
            }
            t = sb[i] - '0';
            b[k2] = b[k2]*10 + t;
        }

        t = 0;
        tt = 0;
        value = 0;
        //i>=0&&j>=0这个&&十分重要，之前就是因为用的逗号，导致出错都不知道怎么回事
        for(i=k1,j=k2; i>=0&&j>=0; --i,--j)
        {
            c[tt++] = (a[i]+b[j]+value)%prime[t];
            value = (a[i]+b[j]+value)/prime[t];
            ++t;
        }
        while(j>=0)
        {
            c[tt++] = (b[j]+value)%prime[t];
            value = (b[j]+value)/prime[t];
            ++t;
            --j;
        }
        while(i>=0)
        {
            c[tt++] = (a[i]+value)%prime[t];
            value = (a[i]+value)/prime[t];
            ++t;
            --i;
        }
        if(value > 0)
            c[tt++] = value;
        for(i=tt-1; i>=0; --i)
        {
            if(i == tt-1)
                cout<<c[i];
            else
                cout<<","<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
