// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = n; i > 0; --i) {
            n = i;

            // convert n to binary string
            string binary = "";
            while (n > 0) {
                binary = char('0' + n % 2) + binary;
                n = n / 2;
            }

            // find the string in s
            if (s.find(binary) == string::npos) 
                return false;
        }
        return true;
    }
};

// Test cases
int main() {
    Solution solution;
    string s;
    int n;

    cout << "Test cses 1" << endl;
    s = "0110";
    n = 3;
    cout << "Expected : true" << endl;
    cout << "Result   : " << (solution.queryString(s, n) ? "true" : "false") << endl << endl;

    cout << "Test cses 2" << endl;
    s = "0110";
    n = 4;
    cout << "Expected : false" << endl;
    cout << "Result   : " << (solution.queryString(s, n) ? "true" : "false") << endl << endl;

    return 0;
}