class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        i=0
        j=i+1
        n=len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        ans=set()
        final=float("-inf")
        ans.add(nums[i])
        res=nums[i]
        while j<n:
            if nums[j] not in ans:
                ans.add(nums[j])
                res+=nums[j]
                final=max(final,res)
                j+=1
            else:
                res-=nums[i]
                ans.remove(nums[i])
                i+=1
        return final               
        
        