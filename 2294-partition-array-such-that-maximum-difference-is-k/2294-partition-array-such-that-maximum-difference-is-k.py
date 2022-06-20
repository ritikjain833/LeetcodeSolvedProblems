class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        
        nums.sort()
        n=len(nums)
        i=0
        j=0
        count=0
        #flag=False
        while j<n:
            if nums[j]-nums[i]<=k:
                j+=1
                #flag=False
            else:
                i=j
                j+=1
                count+=1
                
        return count+1        