#include <iostream>
#include <string>

using namespace std;
using std::string;

string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int ToInt(string s)
{
    int a;
    for(a=0; a<10; ++a)
    {
        if(str[a] == s)
            break;
    }
    return a;
}

int main()
{
    string s;
    string s1[6];
    int a,b,x,y;
    do
    {
        a = 0;
        b = 0;
        cin>>s;
        while(s != "+")
        {
            a = ToInt(s);
            b = b*10 + a;
            cin>>s;
        }
        x = 0;
        y = 0;
        cin>>s;
        while(s != "=")
        {
            x = ToInt(s);
            y = y*10 + x;
            cin>>s;
        }
        if(b+y == 0)
            break;
        cout<<b+y<<endl;
    }while(1);
    return 0;
}


/*
#include <iostream>
#include <string>

using namespace std;
using std::string;

string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int ToInt(string s)
{
    int a;
    for(a=0; a<10; ++a)
    {
        if(str[a] == s)
            break;
    }
    return a;
}

int main()
{
    string s;
    string s1[6];
    unsigned int a,b,x,y;
    while(getline(cin, s))
    {
        a = s.find('+');
        s1[0] = s.substr(0,a-1);
        s1[1] = s.substr(a+2,s.size());
        a = s1[1].find('=');
        s1[1] = s1[1].substr(0,a-1);

        a = s1[0].find(' ');
        if(a != string::npos)
        {
            s1[2] = s1[0].substr(0, a);
            s1[3] = s1[0].substr(a+1,s1[0].size());
            a = ToInt(s1[2]);
            b = ToInt(s1[3]);
            x = a*10 + b;
        }
        else
            x = ToInt(s1[0]);

        a = s1[1].find(' ');
        if(a != string::npos)
        {
            s1[4] = s1[1].substr(0, a);
            s1[5] = s1[1].substr(a+1,s1[1].size());
            a = ToInt(s1[4]);
            b = ToInt(s1[5]);
            y = a*10 + b;
        }
        else
            y = ToInt(s1[1]);
        cout<<s1[2].size()<<'\t'<<s1[3].size()<<'\t'<<s1[4].size()<<'\t'<<s1[5].size()<<endl;
        if(x==0 && y==0)
            break;
        cout<<x+y<<endl;
    }
    return 0;
}
*/

/*#include <iostream>
#include <string>
#include <map>

using namespace std;
using std::string;

//string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int ToInt(string s)
{
    int a;
    switch(s)
    {
    case "zero":
        a = 0;
    case "one":
        a = 1;
        break;
    case "two":
        a = 2;
        break;
    case "three":
        a = 3;
        break;
    case "four":
        a = 4;
        break;
    case "five":
        a = 5;
        break;
    case "six":
        a = 6;
        break;
    case "seven":
        a = 7;
        break;
    case "eight":
        a = 8;
        break;
    case "nine":
        a = 9;
        break;
    }
    return a;
}

int main()
{
    string s;
    string s1[6];
    unsigned int a,b,x,y;
    map<string,unsigned int> m;
    for(a=0; a<10; ++a)
    {
        m[str[a]] = a;
    }
    while(getline(cin, s))
    {
        a = s.find('+');
        s1[0] = s.substr(0,a-1);
        s1[1] = s.substr(a+2,s.size());
        a = s1[1].find('=');
        s1[1] = s1[1].substr(0,a-1);

        a = s1[0].find(' ');
        if(a != string::npos)
        {
            s1[2] = s1[0].substr(0, a);
            s1[3] = s1[0].substr(a+1,s1[0].size());
            a = ToInt(s1[2]);
            b = ToInt(s1[3]);
            x = a*10 + b;
        }
        else
            x = ToInt(s1[0]);

        a = s1[1].find(' ');
        if(a != string::npos)
        {
            s1[4] = s1[1].substr(0, a);
            s1[5] = s1[1].substr(a+1,s1[1].size());
            a = ToInt(s1[4]);
            b = ToInt(s1[5]);
            y = a*10 + b;
        }
        else
            y = ToInt(s1[1]);

        if(x+y == 0)
            break;
        cout<<x+y<<endl;
    }
    return 0;
}
*/
