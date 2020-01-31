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
    int n,k,i;
    ListNode *pHead, *p, *q;
    pHead = new ListNode;
    pHead->next = NULL;
    while(~scanf("%d%d",&n,&k))
    {
        p = pHead;
        for(i=0; i<n; ++i)
        {
            q = new ListNode;
            q->next = NULL;
            scanf("%d", &(q->data));
            p->next = q;
            p = q;
        }
        if(k<=0 || k>n)
        {
            printf("NULL\n");
        }
        else
        {
            p = pHead->next;
            for(i=0; i<k-1; ++i)
            {
                p = p->next;
            }
            q = pHead->next;
            while(p->next)
            {
                q = q->next;
                p = p->next;
            }
            printf("%d\n",q->data);
        }
        while(pHead->next)
        {
            p = pHead->next;
            pHead->next = p->next;
            delete p;
        }
        p = NULL;
        q = NULL;
    }
    return 0;
}
