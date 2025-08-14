// https://leetcode.com/problems/fruit-into-baskets/description/?envType=problem-list-v2&envId=sliding-window

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 3) return n;

        int left = 0, right = 0;
        int maxFruit = 0;
        unordered_map<int , int> fruitCount;

        while (right < n) {
            // If the fruit is in the basket, increase its count
            if(!fruitCount.insert({fruits[right], 1}).second) {
                fruitCount[fruits[right]]++;
            }

            // If the types of fruits exceed 2, shrink the window from the left
            while(fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if(fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                ++left;
            }

            // Update the maximum number of fruits in the basket
            maxFruit = max(maxFruit, right - left + 1);

            // Move the right pointer to expand the window
            ++right;
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