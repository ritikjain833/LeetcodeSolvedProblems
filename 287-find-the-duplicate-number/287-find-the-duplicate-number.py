class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        temp=sorted(nums)
        n=len(nums)
        for i in range(n-1):
            if temp[i]==temp[i+1]:
                return temp[i]
            