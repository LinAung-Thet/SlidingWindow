// https://leetcode.com/problems/repeated-dna-sequences/?envType=problem-list-v2&envId=sliding-window

#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        int n = s.size();

        for (int i = 0; i <= n - 10; ++i){
            string seq = s.substr(i, 10);
            if (!seen.insert(seq).second) {
                repeated.insert(seq);
            }
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};

// Test cases
int main() {
    Solution solution;
    string s;
    vector<string> results;

    cout << "Test case 1" << endl;
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << "Expected : [CCCCCAAAAA, AAAAACCCCC]" << endl;
    cout << "Result   : [" ;
    results = solution.findRepeatedDnaSequences(s);
    for (auto seq : results) {
        cout << seq << ", ";
    }
    cout << "]" << endl << endl;

    cout << "Test case 2" << endl;
    s = "AAAAAAAAAAAAA";
    cout << "Expected : [AAAAAAAAAA]" << endl;
    cout << "Result   : [" ;
    results = solution.findRepeatedDnaSequences(s);
    for (auto seq : results) {
        cout << seq << ",";
    }
    cout << "]" << endl << endl;

    cout << "Test case 3" << endl;
    s = "AAAAAAAAAAA";
    cout << "Expected : [AAAAAAAAAA]" << endl;
    cout << "Result   : [" ;
    results = solution.findRepeatedDnaSequences(s);
    for (auto seq : results) {
        cout << seq << ",";
    }
    cout << "]" << endl << endl;

    return 0;
}