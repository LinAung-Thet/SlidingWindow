// https://leetcode.com/problems/longest-repeating-character-replacement/?envType=problem-list-v2&envId=sliding-window

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0, left = 0, result = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

// Test cases
int main() {
    Solution solution;
    string s;
    int k;

    cout << "Test case 1" << endl;
    s = "ABAB";
    k = 2;
    cout << "Expected : 4" << endl;
    cout << "Result   : " << solution.characterReplacement(s, k) << endl << endl;

    cout << "Test case 2" << endl;
    s = "AABABBA";
    k = 1;
    cout << "Expected : 4" << endl;
    cout << "Result   : " << solution.characterReplacement(s, k) << endl << endl;

    return 0;
}