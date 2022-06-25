class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count=0
        if len(nums) in (1,2):
            return True
        flag=False
        for i in range(len(nums)-1):
            if nums[i]<=nums[i+1]:
                continue
            if flag:
                return False
            if i==0 or nums[i+1]>=nums[i-1]:
                nums[i]=nums[i+1]
            else:
                nums[i+1]=nums[i]
            flag=True    
        return True   