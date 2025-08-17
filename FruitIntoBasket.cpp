// https://leetcode.com/problems/fruit-into-baskets/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last = -1, secondLast = -1;
        int lastCount = 0, curr = 0, maxFruit = 0;

        for (int fruit : fruits) {
            if (fruit == last || fruit == secondLast) {
                curr++;
            } else {
                curr = lastCount + 1;
            }

            if (fruit == last) {
                lastCount++;
            } else {
                lastCount = 1;
                secondLast = last;
                last = fruit;
            }

            maxFruit = max(maxFruit, curr);
        }

        return maxFruit;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> fruits;

    cout << "Test case 1" << endl;
    fruits = {1, 2, 1};
    cout << "Expected: 3" << endl;
    cout << "Result  : " << solution.totalFruit(fruits) << endl << endl;

    cout << "Test case 2" << endl;
    fruits = {0, 1, 2, 2};
    cout << "Expected: 3" << endl;
    cout << "Result  : " << solution.totalFruit(fruits) << endl << endl;

    cout << "Test case 3" << endl;
    fruits = {2, 3, 2, 2};
    cout << "Expected: 4" << endl;
    cout << "Result  : " << solution.totalFruit(fruits) << endl << endl;

    return 0;
}