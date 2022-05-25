class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        temp=[nums[0]]
        n=len(nums)
        for i in range(1,n):
            if nums[i]>temp[-1]:
                temp.append(nums[i])
            else:
                index=bisect_left(temp,nums[i])
                temp[index]=nums[i]
        return len(temp)        
        