#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[101];
    char flag[101];
    int len,i,j,t;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        memset(flag,'0',len*sizeof(char));
        for(i=0;i<len-1;i++)
        {
            if(flag[i]!='0') continue;
            t=0;
            for(j=i+1;j<len;j++)
            {
                if(str[i]==str[j])
                {
                    if(t==0)
                    {
                        printf("%c:%d",str[i],i);
                        flag[i]='1';
                        t=1;
                    }
                    if(t==1)
                    {
                        printf(",%c:%d",str[j],j);
                        flag[j]='1';
                    }
                }
            }
            if(t==1) printf("\n");
        }
    }
    return 0;
}
