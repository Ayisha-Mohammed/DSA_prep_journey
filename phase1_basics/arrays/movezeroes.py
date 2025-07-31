
'''
Two-pointer pattern: 
i (scans), last_non_zero (tracks placement)
#  Swapping only when needed avoids unnecessary moves
# In-place, O(n) time, O(1) space
# Preserves relative order of non-zero elements
'''


class Solution(object):
    def rotate(self, nums, k):
        n=len(nums)
        k%=n
        def reverse(left,right):
            while left < right:
                nums[left] ,nums[right]=  nums[right] ,nums[left]
                left+=1
                right-=1
        reverse(0,n-1)
        reverse(0,k-1)
        reverse(k,n-1)
        