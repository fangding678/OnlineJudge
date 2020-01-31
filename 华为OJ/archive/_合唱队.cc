#include <iostream>

using namespace std;


int main()
{
    int *a,*t1,*t2;
    int n;
    int i,j;
    int max,temp;
    int result;
    while(cin>>n)
    {
        result=0;
        a=new int[n];
        t1=new int[n];
        t2=new int[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        t1[0]=1;
        t2[n-1]=1;
        for(i=1;i<n;i++)
        {
            max=-1;
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    temp=t1[j]+1;
                    max=(max>temp)?max:temp;
                }
            }
            t1[i]=(max==-1)?1:max;
        }
        for(i=n-2;i>=0;i--)
        {
            max=-1;
            for(j=n-1;j>i;j--)
            {
                if(a[i]>a[j])
                {
                    temp=t2[j]+1;
                    max=(max>temp)?max:temp;
                }
            }
            t2[i]=(max==-1)?1:max;
        }
        result=-1;
        for(i=0;i<n;i++)
        {
            result=(t1[i]+t2[i]-1>result)?(t1[i]+t2[i]-1):result;
        }
        cout<<n-result<<endl;
        delete [] a;
        delete [] t1;
        delete [] t2;
    }
    return 0;
}







/*这种动态规划是错误的。因为并不一定包含中间的人
#include <iostream>

using namespace std;

int Lis(int *a,int l)
{
    if(l==0)
        return 1;
    if(a[l]>a[l-1])
        return Lis(a,l-1)+1;
    else
        return Lis(a,l-1);
}

int Lds(int *a,int l,int n)
{
    if(n-l==0)
        return 1;
    if(a[n]<a[n-1])
        return Lds(a,l,n-1)+1;
    else
        return Lds(a,l,n-1);
}

int main()
{
    int *a;
    int n;
    int i;
    int result;
    while(cin>>n)
    {
        result=0;
        a=new int[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n-1;i++)
        {
            result=max(Lis(a,i)+Lds(a,i,n-1)-1,result);
        }
        cout<<n-result<<endl;
        delete [] a;
    }
    return 0;
}
*/
