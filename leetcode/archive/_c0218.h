//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include <set>
#include "__debug"
using namespace std;

// timeout
class Solution1 {
public:
    void interlap(vector<int> &vs, vector<int> &ve, vector<vector<int>> &ans) {
        if (ve[0] > vs[1]) {
            return;
        }
        if (ve[0] == vs[1]) {
            return;
        }
        if (ve[2] > vs[2]) {
            ans.push_back({ve[0], vs[2]});
            if (ve[1] < vs[1]) {
                ans.push_back({ve[1], vs[2]});
            }
        } else if (ve[2] < vs[2]) {
            if (ve[1] > vs[1]) {
                ans.push_back({vs[1], ve[2]});
            }
        }
    }
    bool isContain(vector<int> &an, vector<int> &vec) {
        if (an[0] > vec[0] && an[0] < vec[1] && an[1] < vec[2]) {
            return true;
        }
        return false;
    }
    void mergeH(vector<vector<int>>& buildings) {
        auto _cmp1 = [](vector<int> &v1, vector<int> &v2) -> bool {return v1[2] == v2[2] ? v1[0] < v2[0] : v1[2] < v2[2];};
        sort(buildings.begin(), buildings.end(), _cmp1);
        int len = buildings.size();
        auto b1 = buildings[0];
        int start = b1[0], end = b1[1];
        vector<vector<int>> newBuilding;
        for (int i = 1; i < len; ++i) {
            if (b1[2] == buildings[i][2]) {
                if (buildings[i][0] <= end) {
                    end = buildings[i][1];
                } else {
                    newBuilding.push_back({start, end, b1[2]});
                    b1 = buildings[i];
                    start = b1[0];
                    end = b1[1];
                }
            } else {
                newBuilding.push_back({start, end, b1[2]});
                b1 = buildings[i];
                start = b1[0];
                end = b1[1];
            }
        }
        newBuilding.push_back({start, end, b1[2]});
        buildings.clear();
        auto _cmp2 = [](vector<int> &v1, vector<int> &v2) -> bool {return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];};
        sort(newBuilding.begin(), newBuilding.end(), _cmp2);
        int len2 = newBuilding.size();
        auto b2 = newBuilding[0];
        int height = b2[2];
        for (int i = 1; i < len2; ++i) {
            if (newBuilding[i][0] == b2[0] && newBuilding[i][1] == b2[1]) {
                height = max(height, newBuilding[i][2]);
            } else {
                buildings.push_back({b2[0], b2[1], height});
                b2 = newBuilding[i];
                height = b2[2];
            }
        }
        buildings.push_back({b2[0], b2[1], height});
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> tmpAns;
        mergeH(buildings);
        auto _cmp = [](vector<int> &v1, vector<int> &v2) -> bool {return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];};
        sort(buildings.begin(), buildings.end(), _cmp);
        int len = buildings.size();
        for (int i = 0; i < len; ++i) {
            ans.push_back({buildings[i][0], 0});
            ans.push_back({buildings[i][0], buildings[i][2]});
            ans.push_back({buildings[i][1], 0});
            ans.push_back({buildings[i][1], buildings[i][2]});
        }
        _print(ans);
        cout << "====================" << endl;
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                interlap(buildings[i], buildings[j], ans);
            }
        }
        _print(ans);
        cout << "====================" << endl;
        for (auto &an : ans) {
            bool flag = true;
            for (auto &vec : buildings) {
                if (isContain(an, vec)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                tmpAns.push_back(an);
            }
        }
        cout << "====================" << endl;
        sort(tmpAns.begin(), tmpAns.end(), _cmp);
        _print(tmpAns);
        cout << "====================" << endl;
        ans.clear();
        int tlen = tmpAns.size();
        int j = 0;
        int i = 1;
        int tt = 0;
        while (i < tlen) {
            if (tmpAns[j][0] != tmpAns[i][0]) {
                ans.push_back(tmpAns[j]);
                tt = tmpAns[j][1];
                j = i;
                ++i;
                continue;
            }
            if (tmpAns[j][1] < tmpAns[i][1] && tt < tmpAns[i][1]) {
                j = i;
                tt = tmpAns[i][1];
            } else if (tmpAns[j][1] > tmpAns[i][1] && tt > tmpAns[i][1]) {
                j = i;
                tt = tmpAns[i][1];
            }
            if (i == tlen - 1) {
                ans.push_back(tmpAns[j]);
            }
            ++i;
        }
        tmpAns.clear();
        return ans;
    }
};

// 参考题解，线性扫描法
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<pair<int, int>> all;
        for (auto &b : buildings) {
            all.insert(pair<int, int>(b[0], -b[2]));
            all.insert(pair<int, int>(b[1], b[2]));
        }
        pair<int, int> last(0, 0);
        multiset<int> heights({0});
        for (auto &p : all) {
            if (p.second < 0) {
                heights.insert(-p.second);
            } else {
                heights.erase(heights.find(p.second));
            }
            int maxHeight = *heights.rbegin();
            if (last.second != maxHeight) {
                last.first = p.first;
                last.second = maxHeight;
                ans.push_back({last.first, last.second});
            }
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<vector<int>> buildings;
    buildings.push_back({2,9,10});
    buildings.push_back({3,7,15});
    buildings.push_back({5,12,12});
    buildings.push_back({15,20,10});
    buildings.push_back({19,24,8});
    auto ans = solution.getSkyline(buildings);
    _print(ans);

    buildings.clear();
    buildings.push_back({0,2,3});
    buildings.push_back({2,5,3});
    ans = solution.getSkyline(buildings);
    _print(ans);

    buildings.clear();
    buildings.push_back({1,2,1});
    buildings.push_back({1,2,2});
    buildings.push_back({1,2,3});
    ans = solution.getSkyline(buildings);
    _print(ans);

    buildings.clear();
    buildings.push_back({0,2,3});
    buildings.push_back({2,4,3});
    buildings.push_back({4,6,3});
    ans = solution.getSkyline(buildings);
    _print(ans);

    buildings.clear();
    buildings.push_back({1,20,1});
    buildings.push_back({1,21,2});
    buildings.push_back({1,22,3});
    buildings.push_back({0,2147483647,2147483647});
    ans = solution.getSkyline(buildings);
    _print(ans);

}

