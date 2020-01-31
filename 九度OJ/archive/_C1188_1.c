#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Link;
int main()
{
    int n,p,i,j;
    Node *head;
    Link r,s;
    while(~scanf("%d%d",&n,&p))
    {
        s=(Link)malloc(sizeof(Node));
        s->data=1;
        head=s;
        s->next=s;
        for(i=1;i<n;i++)
        {
            r=(Link)malloc(sizeof(Node));
            r->data=i+1;
            s->next=r;
            r->next=head;
            s=r;
        }
        //s=head;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<p-1;j++)
                s=s->next;
            r=s->next;
            s->next=r->next;
            printf("%d ",r->data);
            free(r);
        }
        printf("%d\n",s->data);
        free(s);
    }
    return 0;
}
