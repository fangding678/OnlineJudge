#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int isLegal(char *str,int len,int jin)
{
    int i;
    if(jin==10)
    {
        if(len==1) return 1;
        for(i=1;i<len-2;i++)
        {
            if(str[i]<'0'||str[i]>'9') return 0;
        }
        if(str[len-1]>='0'&&str[len-1]<='9')
        {
            if(str[len-2]>='0'&&str[len-2]<='9') return 1;
            else return 0;
        }
        else if(tolower(str[len-1])=='l')
        {
            if(tolower(str[len-2])=='u'||(tolower(str[len-1])>='0'&&tolower(str[len-1])<='7'))
                return 1;
            else return 0;
        }
        else if(tolower(str[len-1])=='u')
        {
            if(tolower(str[len-1])>='0'&&tolower(str[len-1])<='9')
                return 1;
            else return 0;
        }
        else return 0;
    }
    else if(jin==8)
    {
        if(len==2)
        {
            if(str[2]>='0'&&str[2]<='7') return 1;
            else return 0;
        }
        for(i=1;i<len-2;i++)
        {
            if(str[i]<'0'||str[i]>'7') return 0;
        }
        if(str[len-1]>='0'&&str[len-1]<='7')
        {
            if(str[len-2]>='0'&&str[len-2]<='7') return 1;
            else return 0;
        }
        else if(tolower(str[len-1])=='l')
        {
            if(len>3)
            {
                if(tolower(str[len-2])=='u'||(tolower(str[len-1])>='0'&&tolower(str[len-1])<='7'))
                    return 1;
                else return 0;
            }
            else
            {
                if(tolower(str[len-1])>='0'&&tolower(str[len-1])<='7')
                    return 1;
                else return 0;
            }
        }
        else if(tolower(str[len-1])=='u')
        {
            if(tolower(str[len-1])>='0'&&tolower(str[len-1])<='9')
                return 1;
            else return 0;
        }
        else return 0;
    }
    else
    {
        if(len==3)
        {
            if((str[2]>='0'&&str[2]<='9')||(str[2]>='a'&&str[2]<='f')) return 1;
            else return 0;
        }
        else if(len==4)
        {
            if(((str[2]>='0'&&str[2]<='9')||(str[2]>='a'&&str[2]<='f'))&&((str[3]>='0'&&str[3]<='9')||(str[3]>='a'&&str[3]<='f')||tolower(str[3])=='u'||tolower(str[3])=='l')) return 1;
            else return 0;
        }
        for(i=2;i<len-2;i++)
        {
            if((str[i]<'0'||str[i]>'9')&&(str[i]<'a'||str[i]>'f')) return 0;
        }
        if((str[len-1]<'0'||str[len-1]>'9')&&(str[len-1]<'a'||str[len-1]>'f'))
        {
            if((str[len-2]<'0'||str[len-2]>'9')&&(str[len-2]<'a'||str[len-2]>'f')) return 1;
            else return 0;
        }
        else if(tolower(str[len-1])=='l')
        {
            if(tolower(str[len-2])=='u'||(tolower(str[len-1])>='a'&&tolower(str[len-1])<='f')||(str[len-1]>='0'&&str[len-1]<='9'))
                return 1;
            else return 0;
        }
        else if(tolower(str[len-1])=='u')
        {
            if((tolower(str[len-1])>='a'&&tolower(str[len-1])<='f')||(str[len-1]>='0'&&str[len-1]<='9'))
                return 1;
            else return 0;
        }
        else return 0;
    }
}
int main()
{
    char str[100];
    int flag,jin,len;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        if(str[0]>'0'&&str[0]<='9') jin=10;
        else if(str[0]=='0'&&tolower(str[1])=='x') jin=16;
        else if(str[0]=='0'&&(str[1]>'0'&&str[1]<='9')) jin=8;
        else
        {
            printf("No\n");
            continue;
        }
        flag=isLegal(str,len,jin);
        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
