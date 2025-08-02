#Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#Note that you must do this in-place without making a copy of the array.

'''Two-pointer pattern: 
i (scans), last_non_zero (tracks placement)
#  Swapping only when needed avoids unnecessary moves
# In-place, O(n) time, O(1) space
# Preserves relative order of non-zero elements
'''

def moveZeroes(nums):
    last_non_zero = 0

    for i in range(len(nums)):
        if nums[i] != 0:
            nums[i], nums[last_non_zero] = nums[last_non_zero], nums[i]
            last_non_zero += 1

#Example:
#Input: nums = [0,1,0,3,12]
#Output: [1,3,12,0,0]

        