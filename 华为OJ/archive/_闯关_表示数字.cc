#include <iostream>
#include <cstring>

using namespace std;

int MarkNum(char *pInStr, char *pOutStr)
{
    int i,j,len;
    len=strlen(pInStr);
    for(i=0,j=0;i<len;i++,j++)
    {
        if(pInStr[i]<='9'&&pInStr[i]>='0')
        {
            if(i<=0||(pInStr[i-1]>'9'||pInStr[i-1]<'0'))
            {
                pOutStr[j++]='*';
                pOutStr[j]=pInStr[i];
            }
            else
                pOutStr[j]=pInStr[i];
            if(i>=len-1||(pInStr[i+1]>'9'||pInStr[i+1]<'0'))
            {
                pOutStr[j++]=pInStr[i];
                pOutStr[j]='*';
            }
            else
                pOutStr[j]=pInStr[i];
        }
        else
            pOutStr[j]=pInStr[i];
    }
    pOutStr[++j]='\0';
    return 0;
}

int main()
{
    char strin[100],strout[200];
    while(cin.getline(strin,100))
    {
        if(MarkNum(strin,strout)==0)
            cout<<strout<<endl;
    }
    return 0;
}
