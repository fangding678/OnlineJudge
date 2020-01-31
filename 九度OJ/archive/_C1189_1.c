#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Link;

int main()
{
    int i,j;
    Link head,s,r;
    s=(Link)malloc(sizeof(Node));
    head=s;
    s->next=head;
    s->data=1;
    for(i=2;i<=21;i++)
    {
        r=(Link)malloc(sizeof(Node));
        r->data=i;
        r->next=head;
        s->next=r;
        s=r;
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<16;j++)
            s=s->next;
        r=s->next;
        s->next=r->next;
        free(r);
    }
    printf("%d\n",s->data);
    return 0;
}
