/*
Problem:
Given a string s, return the index of the first non-repeating character. If none, return -1.

Idea
Step 1: Use unordered_map<char,int> to count frequency.
Step 2: Loop again through string, first char with freq[c]==1 → return index.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> freq;
    
    // Count frequency
    for (char c : s) freq[c]++;
    
    // Find first with freq=1
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    string s = "loveleetcode";
    cout << firstUniqChar(s) << endl; // output 2 ('v')
}
