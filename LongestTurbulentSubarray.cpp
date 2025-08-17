// https://leetcode.com/problems/longest-turbulent-subarray/submissions/1737176037/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private: 
    int compare(int a, int b) {
        if (a == b) return 0;
        else if (a < b) return -1;
        else return 1;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;

        int inc = 1, dec = 1, maxLen = 1;

        for (int i = 1; i < n; ++i) {
            int comparison = compare(arr[i], arr[i - 1]);
            if (comparison == 1) {
                inc = dec + 1;
                dec = 1;
            } else if (comparison == -1) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));
        }

        return maxLen;
    }
};

// Test cases
int main()
{
    Solution solution;
    vector<int> arr;

    cout << "Test case 1" << endl;
    cout << "Expected : 5" << endl;
    arr = {9,4,2,10,7,8,8,1,9};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    cout << "Test case 2" << endl;
    cout << "Expected : 2" << endl;
    arr = {4,8,12,16};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    cout << "Test case 3" << endl;
    cout << "Expected : 1" << endl;
    arr = {100};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    cout << "Test case 4" << endl;
    cout << "Expected : 1" << endl;
    arr = {99};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    cout << "Test case 5" << endl;
    cout << "Expected : 5" << endl;
    arr = {0,1,1,0,1,0,1,1,0,0};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    cout << "Test case 6" << endl;
    cout << "Expected : 1" << endl;
    arr = {100, 100, 100};
    cout << "Result   : " << solution.maxTurbulenceSize(arr) << endl << endl;

    return 0;
}