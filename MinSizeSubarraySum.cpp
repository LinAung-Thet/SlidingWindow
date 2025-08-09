// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] >= target;

        int minLength = INT_MAX;
        int sum = nums[0], l = 0, r = 0;
        while (l < n) {
            if (sum < target) {
                if(++r >= n) 
                    return (minLength == INT_MAX ? 0 : minLength);
                sum += nums[r];
            }
            else {
                minLength = min(r - l + 1, minLength);
                sum -= nums[l++];
                // Update r if l passes r
                if (l > r) {
                    r = l;
                    sum = nums[l];
                }
            }
        }
        return (minLength == INT_MAX ? 0 : minLength);
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums;
    int target;

    cout << "Test case 1" << endl;
    nums = {2,3,1,2,4,3};
    target = 7;
    cout << "Expected : 2" << endl;
    cout << "Result   : " << solution.minSubArrayLen(target, nums) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {1,4,4};
    target = 4;
    cout << "Expected : 1" << endl;
    cout << "Result   : " << solution.minSubArrayLen(target, nums) << endl << endl;

    cout << "Test case 3" << endl;
    nums = {1,1,1,1,1,1,1,1};
    target = 11;
    cout << "Expected : 0" << endl;
    cout << "Result   : " << solution.minSubArrayLen(target, nums) << endl << endl;

    return 0;
}