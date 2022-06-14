class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        i=0
        j=i+1
        n=len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        check=[False]*(10**4+1)
        final=float("-inf")
        check[nums[i]]=True
        res=nums[i]
        while j<n:
            if check[nums[j]]==False:
                check[nums[j]]=True
                res+=nums[j]
                final=max(final,res)
                j+=1
            else:
                res-=nums[i]
                check[nums[i]]=False
                i+=1
        return final               
        
        