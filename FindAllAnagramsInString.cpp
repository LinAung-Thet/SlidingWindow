// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=sliding-window

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        int pLen = p.size();

        // Initialize frequency counts for p and first window of s
        for (int i = 0; i < pLen; ++i) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (pCount == sCount) result.push_back(0);

        // Slide the window over s
        for (int i = pLen; i < s.size(); ++i) {
            sCount[s[i] - 'a']++;                     // Add new char
            sCount[s[i - pLen] - 'a']--;              // Remove old char

            if (sCount == pCount) result.push_back(i - pLen + 1);
        }

        return result;
    }
};

// Test cases
int main() {
    Solution solution;
    string s, p;
    vector<int> indexes;

    cout << "Test case 1" << endl;
    s= "cbaebabacd";
    p = "abc";
    cout << "String: " << s << ", Pattern: " << p << endl;
    indexes = solution.findAnagrams(s, p);
    cout << "Expected : [0 6 ]" << endl;
    cout << "Result   : [";
    for (int index : indexes) {
        cout << index << " ";
    }
    cout << "]" << endl << endl;

    cout << "Test case 2" << endl;
    s= "abab";
    p = "ab";
    cout << "String: " << s << ", Pattern: " << p << endl;
    indexes = solution.findAnagrams(s, p);
    cout << "Expected : [0 1 2 ]" << endl;
    cout << "Result   : [";
    for (int index : indexes) {
        cout << index << " ";
    }
    cout << "]" << endl << endl;

    return 0;
}