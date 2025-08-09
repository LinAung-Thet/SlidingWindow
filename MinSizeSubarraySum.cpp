// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, minLen = n + 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }

        return (minLen <= n) ? minLen : 0;
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