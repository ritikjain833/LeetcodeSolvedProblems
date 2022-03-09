class Solution:
    def balancedStringSplit(self, nums: str) -> int:
        ans=0
        count=0
        for i in range(len(nums)):
            if nums[i]=="L":
                count+=1
            else:
                count-=1
            if count==0:
                ans+=1
        return ans       
                
        
