#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string num = "0";
        string s = "";
        string str;
        int len1 = num1.size();
        int len2 = num2.size();
        int i, j, t;
        i=0, j=0;
        while(i<len1 && num1[i] == '0') ++i;
        while(j<len2 && num2[j] == '0') ++j;
        if(i == len1 || j == len2)
            return num;
        num1 = num1.substr(i);
        num2 = num2.substr(j);
        for(i=len1-1; i>=0; --i) {
            t = num1[i] - '0';
            if(t == 0) {
                s += "0";
                continue;
            }
            str = multiply(t, num2) + s;
            num = add(num, str);
            s += "0";
        }
        return num;
    }
    string multiply(int n, string num2) {
        string res;
        int len2 = num2.size();
        int i, value = 0, t;
        for(i=len2-1; i>=0; --i) {
            t = (num2[i] - '0')*n + value;
            value = t/10;
            res += t%10 + '0';
        }
        if(value > 0)
            res += value + '0';
        reverse(res.begin(), res.end());
        return res;
    }
    string add(string & num1, string & num2) {
        int len1 = num1.size()-1, len2 = num2.size()-1;
        int value = 0, t;
        string res;
        while(len1>=0 && len2>=0) {
            t = num1[len1] - '0' + num2[len2] - '0' + value;
            res += t%10 + '0';
            value = t/10;
            --len1;
            --len2;
        }
        while(len1>=0) {
            t = num1[len1] - '0' + value;
            res += t%10 + '0';
            value = t/10;
            --len1;
        }
        while(len2>=0) {
            t = num2[len2] - '0' + value;
            res += t%10 + '0';
            value = t/10;
            --len2;
        }
        if(value > 0) {
            res += value + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int func()
{
    string num1 = "9";
    string num2 = "99";
    Solution S;
    cout<<S.multiply(num1, num2)<<endl;
    return 0;
}
