#include <iostream>

using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode *left,*right;
}BiTNode, *BiTree;
int preA[1001],inA[1001];

bool createTree(BiTree &T, int *preBegin, int *inBegin, int len)
{
    int index, i;
    bool flagLeft, flagRight;
    if(len<=0)
        return true;
    for(i=0; i<len; ++i)
    {
        if(preBegin[0] == inBegin[i])
            break;
    }
    index = i;
    if(index >= len)
        return false;
    T = new BiTNode;
    T->left=T->right=NULL;
    T->data = preBegin[0];
    flagLeft = createTree(T->left, preBegin+1, inBegin, index);
    flagRight = createTree(T->right, preBegin+index+1, inBegin+index+1, len-index-1);
    if(!(flagLeft&&flagRight))
        return false;
    return true;
}

void postOrder(const BiTree T)
{
    if(T==NULL)
        return ;
    if(T->left)
        postOrder(T->left);
    if(T->right)
        postOrder(T->right);
    cout<<T->data<<' ';
}

int main()
{
    int n,i;
    BiTree T = NULL;
    bool flag;
    while(cin>>n)
    {
        for(i=0; i<n; ++i)
            cin>>preA[i];
        for(i=0; i<n; ++i)
            cin>>inA[i];
        flag = createTree(T, preA, inA, n);
        if(flag == false)
            cout<<"No";
        else
            postOrder(T);
        cout<<endl;
    }
    return 0;
}
