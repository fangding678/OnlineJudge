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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int ts, te;
        vector<Interval>::iterator s, e;
        vector<Interval>::iterator it;
        vector<Interval> ans;
        for(it=intervals.begin(); it != intervals.end(); ++it) {
            if(newInterval.start <= it->end) {
                break;
            }
            ans.push_back(*it);
        }
        s = it;
        if(s == intervals.end()) {
            ans.push_back(newInterval);
            return ans;
        }
        ts = min(newInterval.start, it->start);
        for(; it != intervals.end(); ++it) {
            if(newInterval.end < it->start) {
                break;
            }
        }
        e = it;
        if(e != intervals.begin()) {
            --e;
            te = max(newInterval.end, e->end);
            Interval t(ts, te);
            ans.push_back(t);
        }
        else {
            ans.push_back(newInterval);
        }
        for(;it != intervals.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
