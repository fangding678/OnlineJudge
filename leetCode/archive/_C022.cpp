#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0)
            return res;
        string t(2*n, ' ');
        int i=0;
        generateParenthesisCore(res, t, n, n, i);
        return res;
    }
    void generateParenthesisCore(vector<string> & res, string & t, int m, int n, int i) {
        if(m == 0 && n == 0) {
            res.push_back(t);
            return ;
        }
        if(m == 0) {
            while(n) {
                --n;
                t[i++] = ')';
            }
            res.push_back(t);
            return;
        }
        if(m == n) {
            t[i] = '(';
            generateParenthesisCore(res, t, m-1, n, i+1);
        }
        else {
            t[i] = '(';
            generateParenthesisCore(res, t, m-1, n, i+1);
            t[i] = ')';
            generateParenthesisCore(res, t, m, n-1, i+1);
        }
    }
};

int func()
{
    Solution S;
    vector<string> res = S.generateParenthesis(3);
    for(size_t i=0; i<res.size(); ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}
