// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return n;

        int left = 0, right = 0, maxLength = 0, flip = 0;
        while (right < n) {
            if (nums[right] == 0) {
                if(++flip > k) {
                    // move left until it passes a zero
                    while (left <= right && nums[left] == 1){
                        ++left;
                    }
                    if(nums[left] == 0) {
                        ++left;
                        --flip;
                    }
                }
            }
            maxLength = max(maxLength, right - left + 1);
            ++right;
        }
        return maxLength;
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