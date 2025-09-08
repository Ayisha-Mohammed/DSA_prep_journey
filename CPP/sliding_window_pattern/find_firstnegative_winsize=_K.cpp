// FIXED WIN + QUEUE PATTERN

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegInWindow(vector<int>& arr, int k) {
    deque<int> dq;  // store indices of negative numbers
    vector<int> ans;

    int n = arr.size();
    int l = 0, r = 0;

    while (r < n) {
        // step 1: add current element if negative
        if (arr[r] < 0) {
            dq.push_back(r);
        }

        // step 2: check if window size reached k
        if (r - l + 1 == k) {
            // if deque not empty, first element is our answer
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            } else {
                ans.push_back(0); // no negative in window
            }

            // step 3: before sliding, remove l if it’s in deque
            if (!dq.empty() && dq.front() == l) {
                dq.pop_front();
            }
            l++; // shrink from left
        }
        r++; // expand from right
    }

    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> res = firstNegInWindow(arr, k);
    for (int x : res) cout << x << " ";
    return 0;
}
