class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n=len(nums)
        up=[1]*(n)
        down=[1]*(n)
        for i in range(1,n):
            for j in range(i):
                if nums[i]>nums[j]:
                    up[i]=max(up[i],down[j]+1)
                elif nums[i]<nums[j]:
                    down[i]=max(up[j]+1,down[i])
        return max(up[n-1],down[n-1])            
        
