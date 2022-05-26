class Solution:
    def atmost(self,nums,k):
        d={}
        i=0
        j=0
        n=len(nums)
        count=0
        while j<n:
            d[nums[j]]=d.get(nums[j],0)+1
            while len(d)>k:
                d[nums[i]]=d[nums[i]]-1
                if d[nums[i]]==0:
                    del d[nums[i]]
                i+=1
            j+=1
            count+=(j-i+1)
            
        return count
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.atmost(nums,k)-self.atmost(nums,k-1)
        
        