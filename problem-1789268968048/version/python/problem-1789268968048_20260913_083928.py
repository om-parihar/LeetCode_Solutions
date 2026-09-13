# Last updated: 9/13/2026, 8:39:28 AM
1class Solution:
2    def shadowPairs(self, nums: list[int]) -> int:
3        stack =[]
4        ans=0
5
6        for x in nums:
7            ans+=bisect_left(stack,x)
8
9            while stack and stack[-1]>x:
10                stack.pop()
11
12            stack.append(x)
13
14        return ans