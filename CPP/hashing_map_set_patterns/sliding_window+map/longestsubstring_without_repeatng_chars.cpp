#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, max_len = 0;
    unordered_map<char,int> freq;

    for(int r = 0; r < s.length(); r++){
        freq[s[r]]++;

        // shrink window if duplicate
        while(freq[s[r]] > 1){
            freq[s[l]]--;
            l++;
        }

        max_len = max(max_len, r - l + 1);
    }

    return max_len;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}
