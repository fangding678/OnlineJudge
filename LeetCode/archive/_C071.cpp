#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string p;
        stack<string> st;
        size_t pos = 0;
        while((pos = path.find('/', pos)) != string::npos) {
            path.replace(pos, 1, " ");
            pos += 1;
        }
        istringstream itr(path);
        while(itr>>p) {
            if(p == ".") {
                continue;
            }
            else if(p == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(p);
            }
        }
        p = "";
        while(!st.empty()) {
            p = '/' + st.top() + p;
            st.pop();
        }
        if(p == "") {
            p = "/";
        }
        return p;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
