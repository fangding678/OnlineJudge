#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
};

void PrintNode(ListNode *pHead)
{
    if(!pHead->next)
    {
        printf("NULL\n");
        return ;
    }
    ListNode *p = pHead->next;
    printf("%d",p->data);
    p = p->next;
    while(p)
    {
        printf(" %d",p->data);
        p = p->next;
    }
    printf("\n");
}

void DeleteNode(ListNode *pHead)
{
    ListNode *p = pHead->next;
    ListNode *q;
    if(!p)
        return ;
    q = p->next;
    while(q)
    {
        delete p;
        p = q;
        q = p->next;
    }
    delete p;
}

ListNode* mergeListNode(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;
    ListNode *pHead = NULL;
    if(pHead1->data > pHead2->data)
    {
        pHead = pHead2;
        pHead->next = mergeListNode(pHead1, pHead2->next);
    }
    else
    {
        pHead = pHead1;
        pHead->next = mergeListNode(pHead1->next, pHead2);
    }
    return pHead;
}

int main()
{
    int n,m,i;
    ListNode *pHead1,*pHead2,*p,*q,*pHead;
    pHead1 = new ListNode;
    pHead2 = new ListNode;
    while(~scanf("%d%d", &n, &m))
    {
        pHead1->next = NULL;
        pHead2->next = NULL;
        pHead = NULL;
        p = pHead1;
        for(i=0; i<n; ++i)
        {
            q = new ListNode;
            q->next = NULL;
            scanf("%d",&(q->data));
            p->next = q;
            p = q;
        }
        p = pHead2;
        for(i=0; i<m; ++i)
        {
            q = new ListNode;
            q->next = NULL;
            scanf("%d",&(q->data));
            p->next = q;
            p = q;
        }
        pHead = mergeListNode(pHead1->next, pHead2->next);
        if(pHead == pHead1->next)
            pHead = pHead1;
        else
            pHead = pHead2;
        PrintNode(pHead);
        DeleteNode(pHead);
    }
    return 0;
}
