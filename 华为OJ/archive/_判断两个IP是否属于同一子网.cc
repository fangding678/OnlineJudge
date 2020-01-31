#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;



bool checked_ip(string ip,vector<int> &vip)
{
    vector<string> part;
    string::size_type ip_size=ip.size();
    int pointCount=0;
    int i,num;
    string::size_type index=0;
    string::size_type prePoint=0;
    while((index=ip.find_first_of('.',index))!=string::npos)
    {
        if(index>prePoint)
            part.push_back(ip.substr(prePoint,index-prePoint));
        ++index;
        prePoint=index;
        ++pointCount;
    }
    if(prePoint<ip_size)
        part.push_back(ip.substr(prePoint));
    if(part.size()!=4)
        return false;
    for(i=0;i<4;i++)
    {
        num=atoi(part[i].c_str());
        vip.push_back(num);
        if(num<0||num>255)
            return false;
    }
    return true;
}

bool checked_mask(string mask,vector<int> &vmask)
{
    return checked_ip(mask,vmask);
}

bool checked_same(vector<int> vip1,vector<int> vip2,vector<int> vmask)
{
    int i;
    int r1,r2;
    for(i=0;i<4;i++)
    {
        r1=vip1[i]&vmask[i];
        r2=vip2[i]&vmask[i];
        if(r1!=r2)
            return false;
    }
    return true;
}

int checkNetSegment(string mask, string ip1, string ip2)
{
    vector<int> vip1;
    vector<int> vip2;
    vector<int> vmask;
    if(checked_ip(ip1,vip1)&&checked_ip(ip2,vip2)&&checked_mask(mask,vmask))
    {
        if(checked_same(vip1,vip2,vmask))
            return 0;
        else
            return 2;
    }
    else
        return 1;
}

int main()
{
    string mask,ip1,ip2;

    while(cin>>mask>>ip1>>ip2)
    {
        cout<<checkNetSegment(mask,ip1,ip2)<<endl;
    }
    return 0;
}
