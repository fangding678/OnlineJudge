#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int c;
    Node* lchild;
    Node* rchild;
}Tree[25];

char s1[25],s2[25];
char *str;
int *size0;
int size1,size2;
int loc;

Node* creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node* Insert(Node *T, int i)
{
    if(T == NULL)
    {
        T = creat();
        T->c = i;
    }
    else if(T->c > i)
        T->lchild = Insert(T->lchild, i);
    else if(T->c < i)
        T->rchild = Insert(T->rchild, i);
    return T;
}

void PreOrder(Node *T)
{
    if(T)
        str[(*size0)++] = T->c + '0';
    if(T->lchild)
        PreOrder(T->lchild);
    if(T->rchild)
        PreOrder(T->rchild);
}

void InOrder(Node* T)
{
    if(T->lchild)
        InOrder(T->lchild);
    str[(*size0)++] = T->c + '0';
    if(T->rchild)
        InOrder(T->rchild);

}

int main()
{
    int n,i,j,data;
    char str1[12];
    Node *T1;
    while(cin>>n)
    {
        if(n == 0)
            break;
        str = s1;
        cin>>str1;
        loc = 0;
        T1 = NULL;
        size1 = 0;
        size0 = &size1;
        for(i=0; str1[i]!=0; ++i)
        {
            data = str1[i] - '0';
            T1 = Insert(T1, data);
        }
        PreOrder(T1);
        InOrder(T1);
        str[size1] = 0;
        for(i=0; i<n; ++i)
        {
            str = s2;
            cin>>str1;
            loc = 0;
            T1 = NULL;
            size2 = 0;
            size0 = &size2;
            for(j=0; str1[j]!=0; ++j)
            {
                data = str1[j] - '0';
                T1 = Insert(T1, data);
            }
            PreOrder(T1);
            InOrder(T1);
            str[size2] = 0;
            cout<<((strcmp(s1,s2) == 0)?"YES":"NO")<<endl;
        }
    }
    return 0;
}
