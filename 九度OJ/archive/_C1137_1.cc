#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str1[101],str2[101];
    char is1[101],fs1[101],is2[101],fs2[101],is[101],fs[101];
    int len,leni1,lenf1,leni2,lenf2;
    int n,i,j,t;
    while(scanf("%d",&n) != EOF)
    {
        getchar();
        while(n--)
        {
            scanf("%s",str1);
            scanf("%s",str2);
            //printf("%s\n%s\n",str1,str2);
            //getchar();
            len = strlen(str1);
            for(i=0; str1[i]!='.';++i);
            t = i;
            j=0;
            while(--i>=0)
            {
                is1[j++] = str1[i];
            }
            while(j>1 && is1[j-1] == '0')
                j--;
            leni1 = j;
            is1[j] = 0;
            i = t;
            j=0;
            while(++i<len)
            {
                fs1[j++] = str1[i];
            }
            lenf1 = j;
            fs1[j] = 0;
            //处理另一大浮点数
            len = strlen(str2);
            for(i=0; str2[i]!='.'; ++i);
            t = i;
            j=0;
            while(--i>=0)
            {
                is2[j++] = str2[i];
            }
            while(j>1 && is2[j-1] == '0')
                j--;
            leni2 = j;
            is2[j] = 0;
            i = t;
            j=0;
            while(++i<len)
            {
                fs2[j++] = str2[i];
            }
            lenf2 = j;
            fs2[j] = 0;

            //计算小数部分
            len = lenf1>lenf2 ? lenf1 : lenf2;
            int value = 0;
            for(i=len-1; i>=0; --i)
            {
                if(lenf1>i && lenf2>i)
                {
                    fs[i] = (fs1[i] + fs2[i] + value - '0' - '0')%10 + '0';
                    value = (fs1[i] + fs2[i] + value - '0' - '0')/10;
                }
                else if(lenf1>i)
                {
                    fs[i] = (fs1[i] + value - '0')%10 + '0';
                    value = (fs1[i] + value - '0')/10;
                }
                else if(lenf2>i)
                {
                    fs[i] = (fs2[i] + value - '0')%10 + '0';
                    value = (fs2[i] + value - '0')/10;
                }
            }
            fs[len] = 0;
            //计算整数部分
            len = leni1>leni2 ? leni1 : leni2;
            for(i=0; i<len; ++i)
            {
                if(leni1>i && leni2>i)
                {
                    is[i] = (is1[i] + is2[i] + value - '0' - '0')%10 + '0';
                    value = (is1[i] + is2[i] + value - '0' - '0')/10;
                }
                else if(leni1>i)
                {
                    is[i] = (is1[i] + value - '0')%10 + '0';
                    value = (is1[i] + value - '0')/10;
                }
                else if(leni2>i)
                {
                    is[i] = (is2[i] + value - '0')%10 + '0';
                    value = (is2[i] + value - '0')/10;
                }
            }
            if(value != 0)
                is[i++] = value + '0';
            while(i>1 && is[i-1]=='0')
                i--;
            is[i] = 0;
            len = strlen(fs);
            while(len>1 && fs[len-1] == '0')
                len--;
            fs[len] = 0;
            if(strcmp(is, "0")==0 && strcmp(fs, "0")==0)
            {
                printf("0\n");
                continue;
            }
            for(j=i-1; j>=0; --j)
                printf("%c",is[j]);
            printf(".");
            printf("%s\n",fs);
            //getchar();
        }
    }
    return 0;
}
