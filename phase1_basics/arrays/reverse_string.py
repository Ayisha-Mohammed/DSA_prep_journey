"""
Problem: Reverse String
Link: https://leetcode.com/problems/reverse-string/
Approach: Two-pointer approach (in-place swap)
Time Complexity: O(n) – where n is the number of characters
Space Complexity: O(1) – no extra space used
The reverse string in-place problem is not just about reversing — it's about teaching you:

concepts to learn :

Efficient memory handling
Two-pointer logic
Mutable vs immutable objects
How to write functions that change arguments directly.
"""


class Solution:
    def reverseString(self, s: List[str]) -> None:
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
   
   