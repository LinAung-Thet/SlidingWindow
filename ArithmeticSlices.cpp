// https://leetcode.com/problems/arithmetic-slices/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int count = 0;
        int l = 0, r = 1, d = nums[r++] - nums[l];
        bool arithmetic = false;
        while (r < n) {
            if (nums[r] - nums[r - 1] == d) {
                arithmetic = true;
            }
            else {
                arithmetic = false;
                int length = r - l - 2;
                if (length > 0) {
                    count += (length * (length + 1)) /2;
                }

                l = r - 1;
                d = nums[r] - nums[l];
            }
            ++r;
        }
        if (arithmetic) {
            int length = r - l - 2;
            if (length > 0) {
                count += (length * (length + 1)) /2;
            }
        }
        return count;
    }
};
// Test cases
int main() {
    Solution solution;
    vector<int> nums;

    cout << "Test case 1" << endl;
    nums = {1, 2, 3, 4};
    cout << "Expected : 3" << endl;
    cout << "Result   : " << solution.numberOfArithmeticSlices(nums) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {1};
    cout << "Expected : 0" << endl;
    cout << "Result   : " << solution.numberOfArithmeticSlices(nums) << endl << endl;

    cout << "Test case 3" << endl;
    nums = {0, 2, 3, 4, 5};
    cout << "Expected : 3" << endl;
    cout << "Result   : " << solution.numberOfArithmeticSlices(nums) << endl << endl;

    return 0;
}