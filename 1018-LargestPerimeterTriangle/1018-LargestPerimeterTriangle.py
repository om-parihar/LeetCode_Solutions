# Last updated: 7/25/2026, 10:58:07 PM
class Solution(object):
    def largestPerimeter(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse=True)
        for i in range(len(nums)-2):
            a,b,c=nums[i],nums[i+1],nums[i+2]
            if b+c>a:
                return a+b+c
        return 0
        