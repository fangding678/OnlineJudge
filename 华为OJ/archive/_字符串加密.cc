#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#define M 100
using namespace std;

int s[26];
int i,j,k,len;
char stemp[M];

void encrypt1(char * key,char * data,char * encrypt)
{
    memset(s,0,sizeof(s));
    len=strlen(key);
    k=0;
    for(i=0;i<len;i++)
    {
        j=toupper(key[i])-'A';
        if(s[j]==0)
        {
            stemp[k++]=key[i];
            s[j]=1;
        }
    }
    for(i=0;i<26;i++)
    {
        if(s[i]==0)
            stemp[k++]='A'+i;
    }
    len=strlen(data);
    for(i=0;i<len;i++)
    {
        if(isupper(data[i]))
            encrypt[i]=stemp[static_cast<int>(data[i]-'A')];
        else if(islower(data[i]))
            encrypt[i]=stemp[static_cast<int>(data[i]-'a')]+'a'-'A';
        else
            encrypt[i]=data[i];
    }
    encrypt[i]='\0';

}
int main()
{

    char key[M],data[M],encrypt[M];
    while(cin>>key)
    {
        getchar();
        cin>>data;
        encrypt1(key,data,encrypt);
        cout<<encrypt<<endl;
        memset(encrypt,0,sizeof(encrypt));
        memset(stemp,0,sizeof(encrypt));
    }
    return 0;
}



/*此题要使用原版接口，所以用C做
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    int s[26];
    char c;
    int i,j,len;
    string key,data,stemp,encrypt;
    while(cin>>key)
    {
        getchar();
        getline(cin,data);
        memset(s,0,sizeof(s));
        len=key.length();
        for(i=0;i<len;i++)
        {
            j=toupper(key[i])-'A';
            if(s[j]==0)
            {
                stemp.push_back(toupper(key[i]));
                s[j]=1;
            }
        }
        for(i=0;i<26;i++)
        {
            if(s[i]==0)
            {
                c='A'+i;
                stemp.push_back(c);
            }
        }
        len=data.length();
        for(i=0;i<len;i++)
        {
            if(isupper(data[i]))
                encrypt.push_back(stemp[static_cast<int>(data[i]-'A')]);
            else if(islower(data[i]))
                encrypt.push_back(stemp[static_cast<int>(data[i]-'a')]+'a'-'A');
            else
                encrypt.push_back(data[i]);
        }
        cout<<encrypt<<endl;
        encrypt.clear();
        stemp.clear();
    }
    return 0;
}
*/
