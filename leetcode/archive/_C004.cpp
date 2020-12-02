#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int high1 = nums1.size();
        int high2 = nums2.size();
        int h1 = high1;
        int h2 = high2;
        bool isQi = (h1 + h2)%2 == 0 ? false : true;
        double res = 0.0;
        if(high1 < high2)
            return findMedianSortedArrays(nums2, nums1);
        if(high2 == 0)
        {
            if(high1%2 == 0)
                return 1.0 * (nums1[high1/2] + nums1[high1/2-1]) / 2;
            else
                return 1.0 * nums1[high1/2];
        }
        int low1 = 0;
        int low2 = 0;
        int m = (low1 + high1 - 1)/2;
        int l2 = 0, u2 = 0;
        int mid = (high1 + high2)/2 - 1;
        int a = nums1[0];
        int b = nums2[0];
        while(1) {
            vector<int>::iterator itb = nums2.begin() + low2;
            vector<int>::iterator ite = nums2.begin() + high2;
            pair<vector<int>::iterator, vector<int>::iterator> it= equal_range(itb, ite, nums1[m]);
            vector<int>::iterator itl = it.first;
            vector<int>::iterator itu = it.second;
            l2 = itl - nums2.begin();
            u2 = itu - nums2.begin();
            if(l2 + m > mid) {
                high1 = m;
                high2 = l2;
            }
            else if(u2 + m < mid) {
                low1 = m;
                low2 = u2;
            }
            else {
                break;
            }
            if(m == (high1 + low1)/2) {
                break;
            }
            m = (high1 + low1) / 2;
        }
        if(l2 == h2) {
            if(isQi)
                return nums1[(h1-h2)/2];
            else {
                if(h1 == h2) {
                    return 1.0*(nums1[0] + nums2[h2-1])/2;
                }
                else {
                    return 1.0*(nums1[m] + nums1[m+1])/2;
                }
            }
        }
        a = min(nums1[m], nums2[l2]);
        b = max(nums1[m], nums2[l2]);
        while(l2+1 < h2 && m+1 < h1 && m + l2 < mid) {
            if(nums1[m+1] <= nums2[l2+1]) {
                if(b >= nums1[m+1]) {
                    a = nums1[m+1];
                }
                else {
                    a = b;
                    b = nums1[m+1];
                }
                ++m;
            }
            else {
                if(b >= nums2[l2+1]) {
                    a = nums2[l2+1];
                }
                else {
                    a = b;
                    b = nums2[l2+1];
                }
                ++l2;
            }
        }
        while(l2+1 < h2 && m + l2 < mid) {
            if(b >= nums2[l2]) {
                a = nums2[l2];
            }
            else {
                a = b;
                b = nums2[l2];
            }
            ++l2;
        }
        while(m+1 < h1 && m + l2 < mid) {
            if(b >= nums1[m+1]) {
                a = nums1[m+1];
            }
            else {
                a = b;
                b = nums1[m+1];
            }
            ++m;
        }
        if(m+1 != h1 && nums1[m+1] < b) {
            b = nums1[m+1];
        }
        if(l2+1 != h2 && nums2[l2+1] < b) {
            b = nums1[m+1];
        }
        if(isQi)
            res = max(a, b);
        else
            res = (a + b) * 1.0 / 2;
        return res;
    }
};


int func()
{
    Solution S;
    int a1[] = {3,4};
    int a2[] = {2};
    vector<int> v1(begin(a1), end(a1));
    vector<int> v2(begin(a2), end(a2));
    double res = S.findMedianSortedArrays(v1, v2);
    cout<<res<<endl;
    return 0;
}


/*
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int high1 = nums1.size();
        int high2 = nums2.size();
        double res = 0.0;
        if(high1 < high2)
            return findMedianSortedArrays(nums2, nums1);
        if(high2 == 0)
        {
            if(high1%2 == 0)
                return 1.0 * (nums1[high1/2] + nums1[high1/2-1]) / 2;
            else
                return 1.0 * nums1[high1/2];
        }
        int low1 = 0;
        int low2 = 0;
        int mid1 = (low1 + high1 - 1)/2;
        int mid2 = 0;
        int mid = (high1 + high2)/2 - 1;
        while(1) {
            vector<int>::iterator itb = nums2.begin() + low2;
            vector<int>::iterator ite = nums2.begin() + high2;
            //vector<int>::iterator itl = lower_bound(itb, ite, nums1[mid1]);
            vector<int>::iterator itu = upper_bound(itb, ite, nums1[mid1]);
            mid2 = itu - nums2.begin();
            if(mid2 + mid1 < mid) {
                low2 = mid2;
                low1 = mid1;
            }
            else if(mid2 + mid1 > mid) {
                high2 = mid2 - 1;
                high1 = mid1;
            }
            else {
                break;
            }
            mid1 = (high1 + low1)/2;
        }
        high1 = nums1.size();
        high2 = nums2.size();
        if(mid1+1 < high1 && mid2 > 0 && nums1[mid1+1] < nums2[mid2]) {
            ++mid1;
            --mid2;
        }
        if(mid2 == high2)
            return 1.0*nums1[mid1];
        if(((high1 + high2)&1) == 1)
            res = max(nums1[mid1], nums2[mid2]);
        else
            res = (nums1[mid1] + nums2[mid2]) * 1.0 / 2;
        return res;
    }
};


class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int high1 = nums1.size();
        int high2 = nums2.size();
        double res = 0.0;
        if(high1 < high2)
            return findMedianSortedArrays(nums2, nums1);
        if(high2 == 0)
        {
            if(high1%2 == 0)
                return 1.0 * (nums1[high1/2] + nums1[high1/2-1]) / 2;
            else
                return 1.0 * nums1[high1/2];
        }
        int low1 = 0;
        int low2 = 0;
        int mid1 = (low1 + high1 - 1)/2;
        int m1 = 0, m2 = 0;
        int mid = (high1 + high2)/2 - 1;
        while(1) {
            vector<int>::iterator itb = nums2.begin() + low2;
            vector<int>::iterator ite = nums2.begin() + high2;
            pair<vector<int>::iterator, vector<int>::iterator> it= equal_range(itb, ite, nums1[mid1]);
            vector<int>::iterator itl = it.first;
            vector<int>::iterator itu = it.second;
            m1 = itl - nums2.begin();
            m2 = itu - nums2.begin();
            if(high1 == 0) {
                mid1 = 0;
                m1 = nums2.size() - 1;
                break;
            }
            if(low1 == nums1.size() - 1) {
                mid1 = low1;
                m1 = 0;
                break;
            }
            if(m1 + mid1 > mid) {
                high2 = m1;
                high1 = mid1;
            }
            else if(m2 + mid1 < mid) {
                low2 = m2;
                low1 = mid1;
            }
            else {
                break;
            }
            if((high1 == low1)/2 == mid1) {
                break;
            }
            mid1 = (high1 + low1)/2;
        }
        high1 = nums1.size();
        high2 = nums2.size();
        if(m1 == high2) {
            if((high1 + high2)%2 == 1) {
                return nums1[mid1];
            } else {
                return 1.0*(nums1[mid1+1] + nums1[mid1])/2;
            }
        }
        while(mid1 < high1 && m1 < m2) {
            if(mid1 + m1 == mid)
                break;
            if(mid1 +1 < high1 && m1 + 1 < high2) {
                if(nums1[mid1 + 1] < nums2[m1+1])
                    ++mid1;
                else
                    ++m1;
            }
            else if(mid1 + 1 == high1)
                ++m1;
            else
                ++mid1;
        }
        while(mid1 + m1 < mid)
            ++m1;
        if(mid1 + 1 < high1 && nums2[m1] > nums1[mid1+1]) {
            if(((high1 + high2)&1) == 1)
                return max(nums1[mid1], nums1[mid1+1]);
            else
                return (nums1[mid1] + nums1[mid1+1]) * 1.0 / 2;
        }
        if(m1 == high2)
            return 1.0*nums1[mid1];
        if(((high1 + high2)&1) == 1)
            res = max(nums1[mid1], nums2[m1]);
        else
            res = (nums1[mid1] + nums2[m1]) * 1.0 / 2;
        return res;
    }
};
*/
