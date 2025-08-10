// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/?envType=problem-list-v2&envId=sliding-window

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

    int helper(const string& s, int start, int end, int k) {
        if (end - start < k) return 0;

        vector<int> freq(26, 0);
        for (int i = start; i < end; ++i)
            ++freq[s[i] - 'a'];

        for (int mid = start; mid < end; ++mid) {
            if (freq[s[mid] - 'a'] < k) {
                int next = mid + 1;
                while (next < end && freq[s[next] - 'a'] < k)
                    ++next;
                return max(helper(s, start, mid, k),
                        helper(s, next, end, k));
            }
        }

        return end - start;
    }
};

// Test cases
int main() {
    Solution solution;
    string s;
    int k;

    cout << "Test case 1" << endl;
    s = "aaabb";
    k = 3;
    cout << "Expected : 3" << endl;
    cout << "Result   : " << solution.longestSubstring(s, k) << endl << endl;

    cout << "Test case 2" << endl;
    s = "ababbc";
    k = 2;
    cout << "Expected : 5" << endl;
    cout << "Result   : " << solution.longestSubstring(s, k) << endl << endl;

    return 0;
}