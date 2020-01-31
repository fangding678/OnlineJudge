#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P{
    size_t index;
    int value;
    bool operator < (const P & a) const {
        if(value == a.value) {
            return index < a.index;
        }
        return value < a.value;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        size_t len = ratings.size(), i, ind;
        int res = 0;
        if(len == 1) {
            return 1;
        }
        vector<int> can(len, 0);
        vector<P> po;
        for(i = 0; i < len; ++i) {
            P p= {i, ratings[i]};
            po.push_back(p);
        }
        sort(po.begin(), po.end());
        for(i = 0; i < len; ++i) {
            ind = po[i].index;
            if(ind == len-1) {
                if(ratings[ind-1] == ratings[ind]) {
                    can[ind] = 1;
                }else {
                    can[ind] = can[ind-1] + 1;
                }
            }else if(ind == 0) {
                if(ratings[ind+1] == ratings[ind]) {
                    can[ind] = 1;
                }else {
                    can[ind] = can[ind+1] + 1;
                }
            }else {
                if(ratings[ind-1] == po[i].value || ratings[ind+1] == po[i].value) {
                    if(ratings[ind-1] == po[i].value && ratings[ind+1] == po[i].value) {
                        can[ind] = 1;
                    }
                    else if(ratings[ind-1] == po[i].value) {
                        can[ind] = 1+can[ind+1];
                    }else {
                        can[ind] = 1+can[ind-1];
                    }
                } else {
                    can[ind] = max(can[ind+1], can[ind-1]) + 1;
                }
            }
            res += can[ind];
        }
        return res;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
