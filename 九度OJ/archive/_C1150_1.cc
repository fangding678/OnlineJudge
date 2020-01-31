#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
    bool mark[12];
    //char c[13] = "ABCDEFGHIJKL";
    string str,re;
    char result;
    int n,i,j,k,len1;
    string sa[3];
    string sup,sdown;
    while(cin>>n)
    {
        cin.ignore();
        for(i=0; i<n; ++i)
        {
            sup = "";
            sdown = "";
            memset(mark, 0 ,sizeof(mark));
            for(j=0; j<3; ++j)
            {

                getline(cin,str);
                istringstream itr(str);
                itr>>sa[0]>>sa[1]>>sa[2];
                if(sa[2] == "down")
                {
                    sup += sa[1];
                    sdown += sa[0];
                }
                else if(sa[2] == "even")
                {
                    int l = sa[0].size();
                    for(k=0; k<l; ++k)
                    {
                        int index = sa[0][k] - 'A';
                        mark[index] = true;
                        index = sa[1][k] - 'A';
                        mark[index] = true;
                    }
                }
                else if(sa[2] == "up")
                {
                    sup += sa[0];
                    sdown += sa[1];
                }
            }
            len1 = sup.size();
            for(j=0; j<len1; ++j)
            {
                k = sup[j] - 'A';
                if(mark[k]==false && sdown.find(sup[j])==string::npos)
                {
                    re = "heavy";
                    result = sup[j];
                    break;
                }
            }
            for(j=0; j<len1; ++j)
            {
                k = sdown[j] - 'A';
                if(mark[k]==false && sup.find(sdown[j])==string::npos)
                {
                    re = "light";
                    result = sdown[j];
                    break;
                }
            }
            cout<<result<<" is the counterfeit coin and it is "<<re<<"."<<endl;
        }
    }
    return 0;
}
