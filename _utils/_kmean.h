//
// Created by fangding on 2020-07-17.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <utility>
#include <unordered_map>
using namespace std;

#ifndef ONLINEJUDGE__KMEAN_H
#define ONLINEJUDGE__KMEAN_H

class Kmean {
public:
    const double MAX = 1000000.0;
    const double MM = 0.00001;

    void randSelectCenters(vector<pair<double, double >> points, int k, unordered_map<int, pair<double, double>> &centers) {
        int len = points.size();
        int m = len / k;
        int n = len % k;
        int t = rand() % n;
        for (int i = 0; i < k; i++) {
            centers.insert(make_pair(i, points[i*m+t]));
        }
    }

    double distance(pair<double, double> &p1, pair<double, double> &p2) {
        return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
    }

    int selectGroup(pair<double, double>& point, unordered_map<int, pair<double, double>>& centers) {
        int g = 0;
        double dis = MAX;
        for (auto gg : centers) {
            double d_t = distance(gg.second, point);
            if (d_t < dis) {
                g = gg.first;
                dis = d_t;
            }
        }
        return g;
    }

    bool isEqual(pair<double, double> p1, pair<double, double> p2) {
        return (abs(p1.first - p2.first) < MM) && (abs(p1.second - p2.second) < MM);
    }

    void printVec(vector<pair<double, double>> &vec) {
        for (auto p : vec) {
            cout << "p.first:" << p.first << "; p.second:" << p.second << endl;
        }
    }

    void printVec(unordered_map<int, pair<double, double>> &centers) {
        for (auto p : centers) {
            cout << "key:" << p.first << "p.second.first:" << p.second.first << "; p.second.second:" << p.second.second << endl;
        }
    }

    void printAns(unordered_map<int, vector<pair<double, double>>> &ans) {
        cout << "begin------------------------------" << endl;
        for (auto group : ans) {
            cout << "group : " << group.first << endl;
            printVec(group.second);
        }
        cout << "end------------------------------" << endl;
    }

    pair<double, double> calcCenter(vector<pair<double, double>> &v) {
        pair<double, double> p;
        if (v.size() > 0) {
            double d1 = 0.0;
            double d2 = 0.0;
            for (auto a : v) {
                d1 += a.first;
                d2 += a.second;
            }
            p.first = d1 / v.size();
            p.second = d2 / v.size();
        }
        return p;
    }

    unordered_map<int, vector<pair<double, double>>> calc(vector<pair<double, double >> points, int k) {
        unordered_map<int, pair<double, double>> centers;
        unordered_map<int, vector<pair<double, double>>> ans;
        randSelectCenters(points, k, centers);
        bool flag = true;
        for (int i = 0; i < k; ++i) {
            vector<pair<double, double>> tmpV;
            ans[i] = tmpV;
        }
        while (flag) {
            flag = false;
            for (auto &a : ans) {
                a.second.clear();
                printVec(a.second);
            }
            for (auto point : points) {
                int t = selectGroup(point, centers);
                ans[t].push_back(point);
            }

            for (auto g : ans) {
                int k = g.first;
                pair<double, double> p = calcCenter(g.second);
                if (centers.find(k) != centers.end() && !isEqual(centers[k], p)) {
                    flag = true;
                }
                centers[k] = p;
//                下面的写法错误，并不能覆盖
//                centers.insert(make_pair(k, p));
            }
        }
        printVec(centers);
        printAns(ans);
        return ans;
    }
};

void func() {
    vector<pair<double, double>> points;
    points.push_back(make_pair(1.1, 2.2));
    points.push_back(make_pair(1.2, 2.0));
    points.push_back(make_pair(1.3, 3.1));
    points.push_back(make_pair(1.5, 2.6));
    points.push_back(make_pair(2.5, 1.6));
    int k = 3;
    Kmean kmean;
    kmean.calc(points, k);
//    _print(nums);
}


#endif //ONLINEJUDGE__KMEAN_H
