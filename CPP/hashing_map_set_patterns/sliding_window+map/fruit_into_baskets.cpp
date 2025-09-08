//VARIABLE SIZE WINDOW


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, max_len = 0;
        unordered_map<int, int> freq; // fruit type -> count

        for (int r = 0; r < n; r++) {
            freq[fruits[r]]++;  // add current fruit to the window

            // shrink window if more than 2 types
            while (freq.size() > 2) {
                freq[fruits[l]]--;   // remove left fruit
                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]); // remove type completely
                }
                l++;  // shrink from left
            }

            // update max length
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
