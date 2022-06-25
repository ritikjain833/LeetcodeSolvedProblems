class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count=0
        if len(nums) in (1,2):
            return True
        for i in range(1,len(nums)):
            if nums[i-1]>nums[i]:
                if(count==1):
                    return False
                if i-2>=0 and i+1<len(nums) and nums[i-2]>nums[i] and nums[i-1]>nums[i+1]:
                    return False
                count+=1
            
                
        return True