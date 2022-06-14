class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        ans=0
        
        n=len(nums)
        if sum(nums)==x:
            return n
        current_sum=0
        #minimum operations to remove from both the end will is same as maximizing the length of  the contiguous subarray sum that is desired_sum=sum(nums)-x
        desired_sum=sum(nums)-x
        start=0
        end=0
        #using the approach of sliding window we make use of two pointers one start and end
        while end<n:
            #add the nums[end] to the current sum
            current_sum+=nums[end]
            # if the current_sum reaches more than desired_sum start removing the elements from start
            while start<end and current_sum>desired_sum:
                current_sum-=nums[start]
                start+=1
           # if sum is achieved use the maximum value of ans     
            if current_sum==desired_sum:
                ans=max(ans,end-start+1)
            end+=1
        #if ans ==0 no way we can generate that sum.    
        if ans==0:
            return -1
        else:
            return n-ans