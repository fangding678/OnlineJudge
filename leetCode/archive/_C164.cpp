#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        if (len < 2) {
            return ans;
        }
        int mi = nums[0];
        int ma = nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] > ma) {
                ma = nums[i];
            }
            if (nums[i] < mi) {
                mi = nums[i];
            }
        }
        int bg = max((ma - mi) / (len - 1), 1);
        int bn = (ma - mi) / bg + 1;
        vector<tuple<int, int, int>> bucket;
        for (int j = 0; j < bn; ++j) {
            bucket.push_back(make_tuple(0, ma, mi));
        }
        for (int k = 0; k < len; ++k) {
            int index = (nums[k] - mi) / bg;
            get<0>(bucket[index])++;
            get<1>(bucket[index]) = min(nums[k], get<1>(bucket[index]));
            get<2>(bucket[index]) = max(nums[k], get<2>(bucket[index]));
        }
        int lastMax = get<2>(bucket[0]);
        ans = lastMax - get<1>(bucket[0]);
        for (int i = 1; i < bucket.size(); ++i) {
            if (get<0>(bucket[i]) == 0) {
                continue;
            }
            ans = max(ans, get<1>(bucket[i]) - lastMax);
            lastMax = get<2>(bucket[i]);
        }
        return ans;
    }
};

