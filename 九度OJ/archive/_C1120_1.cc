#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[7];
char s[7];
bool mark[7];
int len;
void DFS(int n)
{
    if(n==len)
    {
        s[len] = 0;
        printf("%s\n",s);
        return ;
    }
    for(int i=0; i<len; ++i)
    {
        if(mark[i])
            continue;
        s[n] = str[i];
        mark[i] = true;
        DFS(n+1);
        mark[i] = false;
    }
}

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        len = strlen(str);
        memset(mark, false, sizeof(mark));
        DFS(0);
        cout<<endl;
    }
    return 0;
}

/*此方法是网上找到的……直接调用STL中写好的API
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
 char str[7];
 while(scanf("%s", str) != EOF)
 {
  int len = strlen(str);
  do
  {
   printf("%s\n", str);
  }
  while(next_permutation(str, str + len));
  printf("\n");
 }
 return 0;
}
*/

/*此方法很好，，较为深入理解回溯法和深度优先搜索。。可惜超时
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[7];
string s;
bool mark[7];
int len;
void DFS(int n)
{
    if(n==len)
    {
        cout<<s<<endl;
        return ;
    }
    for(int i=0; i<len; ++i)
    {
        if(mark[i])
            continue;
        s += str[i];
        mark[i] = true;
        DFS(n+1);
        mark[i] = false;
        s.erase(s.size()-1, 1);
    }
}

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        len = strlen(str);
        memset(mark, false, sizeof(mark));
        DFS(0);
        cout<<endl;
    }
    return 0;
}
*/
