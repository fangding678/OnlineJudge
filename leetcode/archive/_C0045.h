#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(), i;
        int ma = 0, t = 0, num = 0;
        for(i=0; i<len;) {
            if(t >= len-1) {
                break;
            }
            while(i <= t) {
                ma = max(ma, i + nums[i]);
                ++i;
            }
            t = ma;
            num++;
        }
        return num;
    }
};

//Time Limit Exceeded
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(), i, j;
        vector<int> dp(len+1, INT_MAX);
        dp[0] = 0;
        for(i=0; i<len; ++i) {
            for(j=1; j<=nums[i]; ++j) {
                if(i+j < len && dp[i+j] > dp[i] + 1) {
                    dp[i+j] = dp[i] + 1;
                }
            }
        }
        return dp[len-1];
    }
};

int func() {
    Solution S;
    vector<int> vc{2,3,1,1,4};
    cout<<S.jump(vc)<<endl;
    return 0;
}

int func3() {
   char str[100] = "3   J     JD,K";
   char* pch = strtok(str, " ,");
   cout<<pch<<endl;
   while(pch != NULL) {
       pch = strtok(NULL," ,");
       cout<<pch<<endl;
   }
   return 0;
}

int func2()
{
    ifstream in("name.txt");
    string strtmp;
    vector<string> vect;
    while(getline(in, strtmp, '\n')) {
        vect.push_back(strtmp.substr(0, strtmp.find(' ')));
    }
    sort(vect.begin(), vect.end());
    vector<string>::iterator it=unique(vect.begin(), vect.end());
    return 0;
}

int func1()
{
    char a[5][10];
    int i;
    for(i=0;i<4;i++)
        cin.getline(a[i],10,',');
    cin.getline(a[i],10);
    for(i=0;i<5;i++)
        cout<<a[i]<<endl;
}
