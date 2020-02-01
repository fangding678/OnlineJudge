#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode *T = nullptr;
        if(len == 0) {
            return T;
        }
        T = sortedArrayToBST(nums, 0, len-1);
        return T;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        TreeNode *t = nullptr;
        if(low > high) {
            return t;
        }
        int mid = (low + high)/2;
        t = new TreeNode(nums[mid]);
        t->left = sortedArrayToBST(nums, low, mid-1);
        t->right = sortedArrayToBST(nums, mid+1, high);
        return t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
