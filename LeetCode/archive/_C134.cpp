#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> dd;
        int len = gas.size(), i, t, res;
        int sumGas = 0, sumCost = 0;
        for(i=0; i<len; ++i) {
            dd.push_back(gas[i] - cost[i]);
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if(sumGas < sumCost || len == 0) {
            return -1;
        }
        t = 0;
        res = 0;
        for(i = 0; i < len; ++i) {
            if(t + dd[i] < 0) {
                res = i+1;
                t = 0;
                continue;
            }
            t += dd[i];
        }
        return res;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
