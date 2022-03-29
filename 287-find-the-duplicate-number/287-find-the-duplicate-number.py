class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tortoise=hare=nums[0]
        flag=True
        while tortoise!=hare or  flag==True:
            tortoise=nums[tortoise]
            hare=nums[nums[hare]]
            flag=False
        tortoise=nums[0]
        while tortoise!=hare:
            tortoise=nums[tortoise]
            hare=nums[hare]
        return hare    
            
            
            