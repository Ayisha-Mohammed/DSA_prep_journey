"""
Problem: Reverse String
Link: https://leetcode.com/problems/reverse-string/
Approach: Two-pointer approach (in-place swap)
Time Complexity: O(n) – where n is the number of characters
Space Complexity: O(1) – no extra space used
"""


class Solution:
    def reverseString(self, s: List[str]) -> None:
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
    
   