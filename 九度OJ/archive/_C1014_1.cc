#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct People
{
    string name;
    int cnt;
    int score;
    bool operator < (const People &A) const
    {
        return (score < A.score || (score == A.score && name > A.name));
    }
}p[1001];
int number[11];

int main()
{
    int n,m,g;
    int i,j,t,cut;
    while(cin>>n)
    {
        if(n == 0)
            break;
        cin>>m>>g;
        cut = 0;
        for(i=1; i<=m; ++i)
            cin>>number[i];
        for(i=0;i<n;++i)
        {
            cin>>p[i].name>>p[i].cnt;
            p[i].score = 0;
            for(j=0;j<p[i].cnt;++j)
            {
                cin>>t;
                p[i].score += number[t];
            }
            if(g <= p[i].score)
                cut++;
        }
        sort(p, p+n);
        cout<<cut<<endl;
        for(i=n-1; i>=0; --i)
        {
            if(cut == 0)
                break;
            cout<<p[i].name<<" "<<p[i].score<<endl;
            cut--;
        }
    }
    return 0;
}
