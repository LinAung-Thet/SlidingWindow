// https://leetcode.com/problems/subarray-product-less-than-k/submissions/1733041535/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, curr = 0, prod = 1, l = 0;

        for (int r = 0; r < n; ++r) {
            prod *= nums[r];
            while (prod >= k && l < r) {
                prod /= nums[l++];
                if (curr > 0) 
                    --curr;
            }
                
            if (prod < k)
                count += ++curr;
        }
        return count;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums;
    int k;

    cout << "Test case 1" << endl;
    nums = {10, 5, 2, 6};
    k = 100;
    cout << "Expected : 8" << endl;
    cout << "Result   : " << solution.numSubarrayProductLessThanK(nums, k) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {1, 2, 3};
    k = 0;
    cout << "Expected : 0" << endl;
    cout << "Result   : " << solution.numSubarrayProductLessThanK(nums, k) << endl << endl;

    return 0;
}