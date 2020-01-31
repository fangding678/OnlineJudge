#include <iostream>

using namespace std;

int Tree[30];
int main()
{
    char s1[4];
    int n,m;
    int i;
    int level;
    int flag;
    int index1,index2,index3;
    while(cin>>n>>m)
    {
        if(m==0 && n==0)
            break;
        for(i=0; i<30; ++i)
            Tree[i] = -1;
        for(i=0; i<n; ++i)
        {
            cin>>s1;
            index1 = s1[0] - 'A';
            index2 = s1[1] - 'A';
            index3 = s1[2] - 'A';
            Tree[index2] = index1;
            Tree[index3] = index1;
            //Tree[index1] = -2;
        }
        for(i=0; i<m; ++i)
        {
            cin>>s1;
            index1 = s1[0] - 'A';
            index2 = s1[1] - 'A';
            flag = 0;

            index3 = index1;
            level = 0;
            while(Tree[index3] >= 0)
            {
                level++;
                index3 = Tree[index3];
                if(index3 == index2)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag != 1) //这一步十分重要，细节决定成败……
            {
                index3 = index2;
                level = 0;
            }
            while(flag!=1 && Tree[index3] >= 0)
            {
                level++;
                index3 = Tree[index3];
                if(index3 == index1)
                {
                    flag = 2;
                    break;
                }
            }
            if(flag == 0)
            {
                cout<<"-"<<endl;
            }
            else if(flag == 1)
            {
                while(level>2)
                {
                    cout<<"great-";
                    level--;
                }
                if(level == 2)
                    cout<<"grandparent"<<endl;
                if(level == 1)
                    cout<<"parent"<<endl;
            }
            else if(flag == 2)
            {
                while(level>2)
                {
                    cout<<"great-";
                    level--;
                }
                if(level == 2)
                    cout<<"grandchild"<<endl;
                if(level == 1)
                    cout<<"child"<<endl;
            }
        }
    }
    return 0;
}
