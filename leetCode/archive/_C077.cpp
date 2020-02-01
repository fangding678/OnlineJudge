#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> v;
        combineCore(v, n, 1, k);
        return ans;
    }
    void combineCore(vector<int> & v, int n, int i, int k) {
        if(k == 0) {
            ans.push_back(v);
            return ;
        }
        if(i > n || n-i < k-1) {
            return ;
        }
        if(n-i == k-1) {
            while(i <= n) {
                v.push_back(i);
                ++i;
            }
            ans.push_back(v);
            return;
        }
        vector<int> v1 = v;
        v.push_back(i);
        combineCore(v, n, i+1, k-1);
        combineCore(v1, n, i+1, k);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
