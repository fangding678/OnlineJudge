#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str,s1,s2;
    string a[101],t;
    int cnt,i;
    while(getline(cin, str))
    {
        cin>>s1;
        cin>>s2;
        cnt = 0;
        istringstream in(str);
        while(in>>t)
        {
            a[cnt++] = t;
        }
        for(i=0; i<cnt; ++i)
        {
            //cout<<a[i]<<endl;
            if(a[i] == s1)
                a[i] = s2;
        }
        cout<<a[0];
        for(i=1; i<cnt; ++i)
        {
            cout<<" "<<a[i];
        }
        cout<<endl;
        cin.ignore();
    }
    return 0;
}



/*
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str,s1,s2;
    string a[101];
    int cnt,i;
    unsigned int index1,index2;
    while(getline(cin, str))
    {
        cin>>s1;
        cin>>s2;
        cin.ignore();
        //cout<<"str:"<<str.size()<<str<<endl;
        //cout<<"s1:"<<s1.size()<<s1<<endl;
        //cout<<"s2:"<<s2.size()<<s2<<endl;
        cnt = 0;
        index2 = 0;
        index1 = str.find(" ", index2);
        while(index1 != string::npos)
        {
            a[cnt++] = str.substr(index2, index1-index2);
            index2 = index1+1;
            index1 = str.find(" ", index2);
        }
        a[cnt++] = str.substr(index2, str.size());
        for(i=0; i<cnt; ++i)
        {
            //cout<<a[i]<<endl;
            if(a[i] == s1)
                a[i] = s2;
        }
        cout<<a[0];
        for(i=1; i<cnt; ++i)
        {
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
*/
