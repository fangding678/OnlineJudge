#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Stu
{
    string id;
    string name;
    int score;
}stu[100001];
bool isShort1(const Stu &s1, const Stu &s2)
{
    return s1.id < s2.id;
}
bool isShort2(const Stu &s1, const Stu &s2)
{
    return (s1.name < s2.name || (s1.name == s2.name && s1.id < s2.id));
}
bool isShort3(const Stu &s1, const Stu &s2)
{
    return (s1.score < s2.score || (s1.score == s2.score && s1.id < s2.id));
}

void Sort(int n, int c)
{
    switch(c)
    {
    case 1:
        sort(stu, stu+n, isShort1);
        break;
    case 2:
        sort(stu, stu+n, isShort2);
        break;
    case 3:
        sort(stu, stu+n, isShort3);
        break;
    }
}
int main()
{
    int n,c;
    int i;
    int cnt = 0;
    while(cin>>n>>c)
    {
        if(n==0 && c==0)
            break;
        for(i=0; i<n; ++i)
        {
            cin>>stu[i].id>>stu[i].name>>stu[i].score;
        }
        Sort(n, c);
        cout<<"Case "<<++cnt<<":"<<endl;
        for(i=0; i<n; ++i)
        {
            cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }
    }
    return 0;
}
