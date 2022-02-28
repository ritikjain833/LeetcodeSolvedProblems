class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans=[]
        if len(nums)==0:
            return ans
        n=len(nums)
        i=0
        while i<n:
            start=nums[i]
            while i<n-1 and nums[i]+1 ==nums[i+1]:
                i+=1
            if start!=nums[i]:
                ans.append("{}->{}".format(start,nums[i]))
            else:
                ans.append(str(start))   
            i+=1
        return ans        
        
