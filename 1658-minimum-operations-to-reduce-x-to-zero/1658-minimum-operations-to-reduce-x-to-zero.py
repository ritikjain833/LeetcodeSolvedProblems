class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        ans=0
        start=0
        end=0
        n=len(nums)
        if sum(nums)==x:
            return n
        current_sum=0
        desired_sum=sum(nums)-x
        while end<n:
            current_sum+=nums[end]
            while start<end and current_sum>desired_sum:
                current_sum-=nums[start]
                start+=1
            if current_sum==desired_sum:
                ans=max(ans,end-start+1)
            end+=1
        if ans==0:
            return -1
        else:
            return n-ans