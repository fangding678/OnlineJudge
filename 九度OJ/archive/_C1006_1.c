#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000];
    while(scanf("%s",s)!=EOF)
    {
         if(!strstr(s,"z")||!strstr(s,"j")||!strstr(s,"o"))
         {
              printf("Wrong Answer\n");
              continue;
         }
         int c_z=0,c_j=0,i=0;
         while(s[i]&&c_z>=c_j)
         {
              if(s[i]=='z') c_z++;
              else if(s[i]=='j') c_j++;
              i++;
         }
         if(c_z!=1||c_j!=1)
         {
              printf("Wrong Answer\n");
              continue;
         }
         int e1=0,e2=0,e3=0;
         int j=0;
         while(s[j++]!='z')
          e1++;
         while(s[j++]!='j')
          e2++;
         while(s[j++])
          e3++;
         if(e2!=0&&e1*e2==e3)
          printf("Accepted\n");
         else
          printf("Wrong Answer\n");
    }
    return 0;
}

