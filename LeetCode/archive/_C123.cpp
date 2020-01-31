#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, i;
        int n = prices.size();
        if(n==0 || n==1) {
            return ans;
        }
        vector<int> vmi;
        vector<int> vma;
        vector<int> p;
        p.push_back(INT_MAX);
        p.push_back(prices[0]);
        for(i=1; i<n; ++i) {
            if(prices[i] != prices[i-1]) {
                p.push_back(prices[i]);
            }
        }
        p.push_back(-1);
        n = p.size();
        for(i=1; i<n-1; ++i) {
            if(p[i] > p[i-1] && p[i] > p[i+1]) {
                vma.push_back(p[i]);
            }
            else if(p[i] < p[i-1] && p[i] < p[i+1]) {
                vmi.push_back(p[i]);
            }
        }
        n = vma.size();
        if(n == 0) {
            return ans;
        }
        for(i=0; i<n; ++i) {
            ans = max(ans, maxProfitCore(vma, vmi, 0, i) + maxProfitCore(vma, vmi, i, n));
        }
        return ans;
    }
    int maxProfitCore(vector<int>& vma, vector<int>& vmi, int b, int e) {
        int ans = 0, i, t;
        if(e-b==0) {
            return ans;
        }
        t = vmi[b];
        for(i=b; i<e; ++i) {
            t = min(vmi[i], t);
            ans = max(vma[i]-t, ans);
        }
        return ans;
    }
};

//此方法超时
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if(n==0 || n==1) {
            return ans;
        }
        int m, i;
        for(i=0; i<n; ++i) {
            m = maxProfitCore(prices, 0, i) + maxProfitCore(prices, i, n);
            ans = max(ans, m);
        }
        return ans;
    }
    int maxProfitCore(vector<int>& prices, int b, int e) {
        int ans = 0;
        int n = e - b;
        if(n==0 || n==1) {
            return ans;
        }
        int i, m = prices[b];
        for(i=b+1; i<e; ++i) {
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
