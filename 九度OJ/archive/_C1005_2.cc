#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    int school[101];
    int GE,GI,GS;
    int id;
    bool operator < (const Student &A) const
    {
        return !(GS<A.GS || (GS==A.GS && (GE<A.GE)));
    }
    bool operator == (const Student &A) const
    {
        if(GE == A.GE && GI == A.GI)
        {
            for(int i=0; i<101; ++i)
            {
                if(school[i] != A.school[i])
                    return false;
            }
            return true;
        }
        return false;
    }
}stu[40001];

struct Result
{
    int schoolID;
    int studentID;
    bool operator < (const Result &A) const
    {
        return (schoolID < A.schoolID || (schoolID == A.schoolID && studentID < A.studentID));
    }
}result[40001];

int main()
{
    int n,m,k;
    int i,j,t,h;
    int a[101];
    while(cin>>n>>m>>k)
    {
        for(i=0; i<m; ++i)
            cin>>a[i];
        for(i=0; i<n; ++i)
        {
            cin>>stu[i].GE>>stu[i].GI;
            stu[i].id = i;
            stu[i].GS = stu[i].GE + stu[i].GI;
            for(j=0; j<101; ++j)
                stu[i].school[j] = -1;
            for(j=0; j<k; ++j)
                cin>>stu[i].school[j];
        }
        sort(stu, stu+n);
        h = 0;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<k; ++j)
            {
                t = stu[i].school[j];
                if(a[t] > 0)
                {
                    a[t]--;
                    result[h].schoolID = t;
                    result[h].studentID = stu[i].id;
                    ++h;
                    break;
                }
                else if(a[t] == 0)
                {
                    //int s = result[h-1].studentID;
                    if(i == 0)
                        break;
                    if(stu[i-1] == stu[i])
                    {
                        result[h].schoolID = result[h-1].schoolID;
                        result[h].studentID = stu[i].id;
                        ++h;
                        break;
                    }
                }
            }
        }
        sort(result, result+h);
        t = 0;
        int flag;
        for(i=0; i<m; ++i)
        {
            flag = 0;
            while(t<h && result[t].schoolID == i)
            {
                if(flag++ == 0)
                {
                    cout<<result[t].studentID;
                }
                else
                    cout<<" "<<result[t].studentID;
                t++;
            }
            cout<<endl;
        }
    }
    return 0;
}
