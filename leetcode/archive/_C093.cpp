#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        int len = s.size();
        if(len < 4 || len > 12) {
            return ans;
        }
        string st;
        string c = ".";
        int i, j, k;
        for(i=1; i<len-2 && i<=3; ++i) {
            for(j=i+1; j<len-1 && j<=i+3; ++j) {
                for(k=j+1; k<len && k<=j+3; ++k) {
                    if(isCheck(s, i, j, k)) {
                        st = s;
                        st.insert(k, c);
                        st.insert(j, c);
                        st.insert(i, c);
                        ans.push_back(st);
                    }
                }
            }
        }
        return ans;
    }
    bool isCheck(string &s, int i, int j, int k) {
        if(isCheckCore(s.substr(0, i)) && isCheckCore(s.substr(i, j-i)) &&
           isCheckCore(s.substr(j, k-j)) && isCheckCore(s.substr(k))) {
            return true;
        }
        return false;
    }
    bool isCheckCore(string st) {
//        if(l==1 && isdigit(s[b])) {
//            return true;
//        }
//        if(l==2 && isdigit(s[b]) && isdigit(s[b+1])) {
//            return true;
//        }
//        if(l==3 && ((s[b]=='1' && isdigit(s[b+1] &&isdigit(s[b+2])))
//                    || (s[b]=='2' && ((s[b+1]=='5' && s[b+2]<='5' && s[b+2]>='0') ||
//                                      (s[b+1]<'5' && s[b+1]>='0' && isdigit(s[b+2]))) ))) {
//                                        return true;
//                                      }
        if(st.size()==3 && st <= "255" && st >="100") {
            return true;
        }
        if(st.size()==2 && st <= "99" && st >= "10") {
            return true;
        }
        if(st.size()==1 && st <= "9" && st >= "0") {
            return true;
        }
        return false;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
