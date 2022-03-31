class Solution:
    def getminimum(self,prefix,dp,curr_index,sc,n):
        if(dp[curr_index][sc]!=-1):
            return dp[curr_index][sc]
        if sc==1:
            return prefix[n]-prefix[curr_index]
        minimum_largest_sum=float("inf")
        for i in range(curr_index,n-sc+1):
            first_split_sum=prefix[i+1]-prefix[curr_index]
            largest_split_sum=max(first_split_sum,self.getminimum(prefix,dp,i+1,sc-1,n))
            minimum_largest_sum=min(minimum_largest_sum,largest_split_sum)
            if first_split_sum>=minimum_largest_sum:
                break
        dp[curr_index][sc]=minimum_largest_sum
        return dp[curr_index][sc]
    def splitArray(self, nums: List[int], m: int) -> int:
        n=len(nums)
        dp=[[-1]*(m+1) for _ in range(n)]
        prefix=[0]*(n+1)
        for i in range(0,n):
            prefix[i+1]=prefix[i]+nums[i]
        return self.getminimum(prefix,dp,0,m,n)    