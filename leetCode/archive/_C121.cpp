#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if(n==0 || n==1) {
            return ans;
        }
        int i, m = prices[0];
        for(i=1; i<n; ++i) {
            m = min(m, prices[i]);
            ans = max(ans, prices[i]-m);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
