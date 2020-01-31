#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,i,top;
    int a[10001];
    char ch;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n<=0||n>10000)
            continue;
        top=0;
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='P')
                scanf("%d",&a[top++]);
            else if(ch=='O'&&top>0)
                top--;
            else if(ch=='A')
            {
                if(top<=0) printf("E\n");
                else printf("%d\n",a[top-1]);
            }
        }
        printf("\n");
    }
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,i,top;
    int a[10001];
    char ch[10];
    while(n!=0)
    {
        scanf("%d",&n);
        if(n<=0||n>10000)
            continue;
        top=0;
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%s",ch);
            if(ch[0]=='P')
                scanf("%d",&a[top++]);
            else if(ch[0]=='O'&&top>0)
                top--;
            else if(ch[0]=='A')
            {
                if(top<=0) printf("E\n");
                else printf("%d\n",a[top-1]);
            }
        }
        printf("\n");
    }
    return 0;
}
*/
