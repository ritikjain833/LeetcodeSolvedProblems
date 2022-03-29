class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #tortoise runs one step at a time
        #hare runs two steps at a time
        #since there are duplicates so hare and tortoise should intersected at some point. but this doesn't guarantee the entry point of the cycle.
        tortoise=hare=nums[0]
        flag=True
        while tortoise!=hare or  flag==True:
            tortoise=nums[tortoise]
            hare=nums[nums[hare]]
            flag=False
        #usedto find the entry point of the cycle    
        tortoise=nums[0]
        while tortoise!=hare:
            tortoise=nums[tortoise]
            hare=nums[hare]
        return hare    
            
            
            
