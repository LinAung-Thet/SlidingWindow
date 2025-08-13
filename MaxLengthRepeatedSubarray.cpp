// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // Convert nums2 to a string
        std::string strnum2;
        for (int x : nums2) {
            strnum2 += static_cast<char>(x);
        }

        std::string strmax;
        int ans = 0;

        for (int num : nums1) {
            strmax += static_cast<char>(num);

            // Check if strmax is a substring of strnum2
            if (strnum2.find(strmax) != std::string::npos) {
                ans = std::max(ans, static_cast<int>(strmax.size()));
            } else {
                strmax.erase(0, 1);  // Remove first character
            }
        }

        return ans;
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