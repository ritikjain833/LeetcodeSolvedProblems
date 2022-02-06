class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for j in range(len(nums)):
            #corner cases when i==0 or i==1
            #when nums[j]!=nums[i-2]
            if i < 2 or nums[j] > nums[i-2]:
                nums[i] = nums[j]
                i += 1
        return i
        
