#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char ans[3001][3001];
char s[3001][3001];
char str[6][6];

void Print(int q, int n, int step)
{
    int i,j,k,l;
    while(q > 1)
    {
        for(i=0; i<n; ++i)
        {
            for(j=0; j<n; ++j)
            {
                if(str[i][j] != ' ')
                {
                    for(k=0; k<step; ++k)
                    {
                        for(l=0; l<step; ++l)
                        {
                            ans[i*step+k][j*step+l] = s[k][l];
                        }
                    }
                }
                else
                {
                    for(k=0; k<step; ++k)
                    {
                        for(l=0; l<step; ++l)
                        {
                            ans[i*step+k][j*step+l] = ' ';
                        }
                    }
                }
            }
        }
        step *= n;
        for(i=0; i<step; ++i)
        {
            ans[i][step] = '\0';
            strcpy(s[i],ans[i]);
        }
        q--;
    }
    for(i=0; i<step; ++i)
        puts(ans[i]);
}
int main()
{
    int i;
    int n,q;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        getchar();
        for(i=0; i<n; ++i)
        {
            gets(str[i]);
            strcpy(s[i], str[i]);
            strcpy(ans[i], str[i]);
        }
        scanf("%d",&q);
        Print(q, n, n);
    }
    return 0;
}
