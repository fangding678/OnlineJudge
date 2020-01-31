#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode* next;
};

void Print(ListNode **pHead)
{
    if(*pHead == NULL || pHead == NULL)
        return;
    if((*pHead)->next != NULL)
    {
        Print(&((*pHead)->next));
    }
    printf("%d\n",(*pHead)->data);
}

int main()
{
    ListNode *pHead=NULL, *pTemp=NULL, *p=NULL;
    int value;
    while(cin>>value && value!=-1)
    {
        if(pHead==NULL)
        {
            pHead = new ListNode;
            pHead->data = value;
            pHead->next = NULL;
            p = pHead;
        }
        else
        {
            pTemp = new ListNode;
            pTemp->data = value;
            pTemp->next = NULL;
            p->next = pTemp;
            p = pTemp;
        }
    }
    Print(&pHead);
    return 0;
}
