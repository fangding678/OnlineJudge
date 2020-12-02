#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return findM(nums, 0, nums.size()-1);
    }

    int findM(vector<int> &nums, int left, int right) {
        int mid;
        while (left < right) {
            if (left == right || right == left + 1) {
                return min(nums[left], nums[right]);
            }
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            mid = (left + right) / 2;
            if (nums[mid] == nums[right] && nums[mid] == nums[left]) {
                return min(findM(nums, left, mid), findM(nums, mid+1, right));
            }
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                if (nums[mid] > nums[right]) {
                    left = mid + 1;
                } else {
                    return nums[mid];
                }
            }
        }
        return min(nums[left], nums[right]);
    }
};

