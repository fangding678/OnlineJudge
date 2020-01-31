#include <iostream>
#include <cstring>

using namespace std;

char str1[30],str2[30];
int n;
int Cn[22][22];
void init()
{
    Cn[1][0] = Cn[1][1] = 1;
    for(int i=2; i<22; i++)
    {
        Cn[i][0] = Cn[i][i] = 1;
        for(int j=1; j<i; j++)
        {
            Cn[i][j] = Cn[i-1][j] + Cn[i-1][j-1];
        }
    }
}
int TT(int s1,int s2,int len)
{
    if(len<=1)
        return n;
    int i,j;
    int k = 0;
    int result = 1;
    for(i=0; i<len;)
    {
        j = i;
        while(j<len && str1[s1+i] != str2[s2+j]) j++;
        if(j>i)
            result *= TT(s1+i+1, s2+i, j-i);
        ++k;
        i = j+1;
    }
    result *= Cn[n][k];
    return result;
}

int main()
{
    int len;
    int ans;
    init();
    while(cin>>n)
    {
        if(n==0)
            break;
        cin>>str1>>str2;
        len = strlen(str1);
        ans = 1;
        if(len > 1)
            ans = TT(1,0,len-1);
        cout<<ans<<endl;
    }
    return 0;
}


/*此方法将会溢出。因为13！会大于最大的32位浮点数
int Cn(int k)
{
    int re = N;
    int i = n - k;
    while(k > 0)
    {
        re /= k;
        k--;
    }
    while(i > 0)
    {
        re /= i;
        i--;
    }
    return re;
}
*/
