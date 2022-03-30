class Solution:
    def maxsum(self,arr,dp,index,k):
        if index>=len(arr):
            return 0
        if dp[index]!=-1:
            return dp[index]
        curr_max=0
        sum_max=0
        for j in range(k):
            to=index+j
            if to>=len(arr):
                break
            curr_max=max(curr_max,arr[to])
            left_sum=curr_max*(j+1)
            right_sum=self.maxsum(arr,dp,to+1,k)
            sum_max=max(sum_max,left_sum+right_sum)
        dp[index]=sum_max
        return dp[index]
            
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n=len(arr)
        dp=[-1]*(n)
        return self.maxsum(arr,dp,0,k)
        
        