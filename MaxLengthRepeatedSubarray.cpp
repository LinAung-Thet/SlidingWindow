// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums1, nums2;

    cout << "Test case 1" << endl;
    nums1 = {1, 2, 3, 2, 1};
    nums2 = {3, 2, 1, 4, 7};
    cout << "Expected : 3" << endl;
    cout << "Result   : "  << solution.findLength(nums1, nums2) << endl << endl;

    cout << "Test case 3" << endl;
    nums1 = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    nums2 = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    cout << "Expected : 9" << endl;
    cout << "Result   : "  << solution.findLength(nums1, nums2) << endl << endl;

    return 0;
}