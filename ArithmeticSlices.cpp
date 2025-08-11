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
        int curr = 0;

        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++curr;
                count += curr;
            } else {
                curr = 0;
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