// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < 1 || n2 < 1) 
            return 0;

        int maxLength = 0, l1 = 0;
        while (l1 < n1) {
            int  l2 = 0;
            while (l2 < n2 && l1 < n1) { 
                int length = 0, buf1 = l1, buf2 = l2;
                while (nums1[buf1] == nums2[buf2]) {
                    ++buf1; ++buf2; ++length;
                    if (buf1 >= n1 || buf2 >= n2)
                        break;
                }
                maxLength = max(maxLength, length);
                ++l2;
            }
            ++l1;
        }
        return maxLength;
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