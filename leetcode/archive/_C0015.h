#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int i, j, k, t, len = nums.size();
        sort(nums.begin(), nums.end());
        if(len == 0 || nums[0] > 0 || nums[len-1] < 0) {
            return res;
        }
        pair<vector<int>::iterator, vector<int>::iterator> median =
        equal_range(nums.begin(), nums.end(), 0);
        int l = median.first - nums.begin();
        int u = median.second - nums.begin();

        //һ�����������
        t = 0;
        for(i=l-1; i>=0; --i) {
            if(t == nums[i])
                continue;
            t = nums[i];
            j = u;
            k = len-1;
            while(j < k) {
                if(nums[j] + nums[k] + nums[i] == 0) {
                    vector<int> t{nums[i], nums[j], nums[k]};
                    res.push_back(t);
                    ++j;
                    --k;
                    while(j<k && nums[j-1]==nums[j] && nums[k+1]==nums[k]) {
                        ++j;
                        --k;
                    }
                }
                else if(nums[j] + nums[k] + nums[i] < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
        }
        //����һ�������
        t = 0;
        for(i=u; i<len; ++i) {
            if(t == nums[i])
                continue;
            t = nums[i];
            j = 0;
            k = l-1;
            while(j < k) {
                if(nums[j] + nums[k] + nums[i] == 0) {
                    vector<int> t{nums[j], nums[k], nums[i]};
                    res.push_back(t);
                    ++j;
                    --k;
                    while(j<k && nums[j-1]==nums[j] && nums[k+1]==nums[k]) {
                        ++j;
                        --k;
                    }
                }
                else if(nums[j] + nums[k] + nums[i] < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
        }
        //ȫ����0�����
        if(u-l == 0) {
            return res;
        }
        if(u-l >= 3) {
            vector<int> t{0,0,0};
            res.push_back(t);
        }
        //�м���0�����
        j = l-1;
        k = u;
        while(j>=0 && k<len) {
            i = nums[j];
            if(nums[j] + nums[k] == 0) {
                vector<int> t{nums[j], 0, nums[k]};
                res.push_back(t);
                --j;
                ++k;
                while(j>=0 && i == nums[j])
                    --j;
            }
            else if(nums[j] + nums[k] < 0) {
                ++k;
            }
            else {
                --j;
            }
        }

        return res;
    }
};

int func()
{
    Solution S;
    vector<int> v{3,-2,1,0};
    vector<vector<int>> res = S.threeSum(v);
    for(size_t i=0; i<res.size(); ++i) {
        for(size_t j=0; j<res[i].size(); ++j) {
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
