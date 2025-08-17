// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                --k;
            }

            while (k < 0) {
                if (nums[left] == 0) {
                    ++k;
                }
                ++left;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums;
    int k;

    cout << "Test case 1" << endl;
    nums = {1,1,1,0,0,0,1,1,1,1,0};
    k = 2;
    cout << "Expected : 6" << endl;
    cout << "Result   : " << solution.longestOnes(nums, k) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    k = 3;
    cout << "Expected : 10" << endl;
    cout << "Result   : " << solution.longestOnes(nums, k) << endl << endl;

    return 0;
}