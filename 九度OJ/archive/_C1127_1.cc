#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    map<char, char> m;
    char s1[60] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s2[60] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    char str[201];
    int i,len;
    len = strlen(s1);
    for(i=0; i<len; ++i)
        m[s1[i]] = s2[i];
    scanf("%s",s1);
    while(strcmp(s1,"ENDOFINPUT") != 0)
    {
        getchar();
        gets(str);
        len = strlen(str);
        for(i=0; i<len; ++i)
        {
            if(str[i]>='A' && str[i]<='Z')
                str[i] = m[str[i]];
        }
        scanf("%s",s2);
        printf("%s\n",str);
        //getchar();
        scanf("%s",s1);
    }
    return 0;
}
