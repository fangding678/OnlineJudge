#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
};

int main()
{
    int t,i;
    ListNode *pHead = new ListNode;
    ListNode *p, *q;
    pHead->next = NULL;
    while(scanf("%d",&t)!=EOF)
    {
        p = pHead;
        for(i=0; i<t; ++i)
        {
            q = new ListNode;
            q->next = NULL;
            scanf("%d",&(q->data));
            p->next = q;
            p = q;
        }
        if(!pHead->next)
        {
            printf("NULL\n");
        }
        else
        {
            p = pHead;
            q = p->next;
            pHead->next = NULL;
            while(q)
            {
                p = q;
                q = p->next;
                p->next = pHead->next;
                pHead->next = p;
            }
            p = pHead->next;
            printf("%d", p->data);
            p = p->next;
            while(p)
            {
                printf(" %d", p->data);
                p = p->next;
            }
            printf("\n");
            p = pHead->next;
            q = p->next;
            while(q)
            {
                delete p;
                p = q;
                q = p->next;
            }
            delete p;
        }
        pHead->next = NULL;
    }
    return 0;
}
