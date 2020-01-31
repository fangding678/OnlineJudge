#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

void Encrypt (char aucPassword[], char aucResult[])
{
    int i=0;
    while(aucResult[i]!='\0')
    {
        if(isalpha(aucResult[i]))
        {
            if(islower(aucResult[i]))
                aucPassword[i]=(static_cast<int>((aucResult[i]-'a'+1)))%26+'A';
            else
                aucPassword[i]=(static_cast<int>((aucResult[i]-'A'+1)))%26+'a';
        }
        else if(isalnum(aucResult[i]))
            aucPassword[i]=(static_cast<int>((aucResult[i]-'0'+1)))%10+'0';
        else
            aucPassword[i]=aucResult[i];
        i++;
    }
    aucPassword[i]='\0';
}
int unEncrypt (char result[], char password[])
{
    int i=0;
    while(password[i]!='\0')
    {
        if(isalpha(password[i]))
        {
            if(islower(password[i]))
                result[i]=(static_cast<int>((password[i]-'a'+25)))%26+'A';
            else
                result[i]=(static_cast<int>((password[i]-'A'+25)))%26+'a';
        }
        else if(isalnum(password[i]))
            result[i]=(static_cast<int>((password[i]-'0'+9)))%10+'0';
        else
            result[i]=password[i];
        i++;
    }
    result[i]='\0';
    return 0;
}
int main()
{
    char result1[101],password1[101];
    char result2[101],password2[101];
    while(cin>>result1>>password2)
    {
        Encrypt(password1,result1);
        unEncrypt(result2,password2);
        cout<<password1<<endl;
        cout<<result2<<endl;
    }
    return 0;
}
