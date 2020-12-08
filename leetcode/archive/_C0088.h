#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int i = m, j = n;
        int k = m+n;
        while(i>0 && j>0) {
            if(nums1[i-1] <= nums2[j-1]) {
                nums1[--k] = nums2[--j];
            }
            else {
                nums1[--k] = nums1[--i];
            }
        }
        while(j>0) {
            nums1[--k] = nums2[--j];
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
