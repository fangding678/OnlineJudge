#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) {
            return false;
        }
        int n = matrix[0].size();
        int low = 0, high = m-1, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target) {
                break;
            }
            else if(matrix[mid][0] >= target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(low > high) {
            return false;
        }
        low = 0;
        high = n-1;
        m = mid;
        while(low <= high) {
            mid = (low+high)/2;
            if(matrix[m][mid] == target) {
                return true;
            }
            else if(matrix[m][mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return false;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
