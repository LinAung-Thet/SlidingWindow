// https://leetcode.com/problems/binary-subarrays-with-sum/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (left <= right && sum > goal) {
                sum -= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums;
    int goal;

    cout << "Test case 1" << endl;
    nums = {1,0,1,0,1};
    goal = 2;
    cout << "Numbers : [1,0,1,0,1]" << endl;
    cout << "Goal : " << goal << endl;
    cout << "Expected : 4" << endl;
    cout << "Result   : " << solution.numSubarraysWithSum(nums, goal) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {0,0,0,0,0};
    goal = 0;
    cout << "Numbers : [0,0,0,0,0]" << endl;
    cout << "Goal : " << goal << endl;
    cout << "Expected : 15" << endl;
    cout << "Result   : " << solution.numSubarraysWithSum(nums, goal) << endl << endl;

    cout << "Test case 3" << endl;
    nums = {0,1,1,1,1};
    goal = 3;
    cout << "Numbers : [0,1,1,1,1]" << endl;
    cout << "Goal : " << goal << endl;
    cout << "Expected : 3" << endl;
    cout << "Result   : " << solution.numSubarraysWithSum(nums, goal) << endl << endl;

    return 0;
}