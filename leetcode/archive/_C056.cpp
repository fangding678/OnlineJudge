#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval & a, Interval & b) {
    if(a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int len = intervals.size();
        if(len == 0) {
            return ans;
        }
        int s = intervals[0].start, e = intervals[0].end;
        for(int i=1; i<len; ++i) {
            if(e >= intervals[i].start) {
                e = max(intervals[i].end, e);
            }
            else {
                Interval t(s, e);
                ans.push_back(t);
                s = intervals[i].start;
                e = intervals[i].end;
            }
        }
        Interval t(s, e);
        ans.push_back(t);
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
