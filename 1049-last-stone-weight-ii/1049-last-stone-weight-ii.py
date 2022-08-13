class Solution:
    def lastStoneWeightII(self, arr: List[int]) -> int:
        sum1=sum(arr)
        n=len(arr)
        dp=[[False]*(sum1+1) for _ in range(n+1)]
        for i in range(n+1):
            dp[i][0]=True
        for i in range(1,n+1):
            for j in range(1,sum1+1):
                if arr[i-1]<=j:
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]]
                else:
                    dp[i][j]=dp[i-1][j]
        sum2=sum1//2
        mini=float("inf")
        for j in range(sum2+1):
            if dp[-1][j]==True:
                mini=min(mini,sum1-2*(j))
        return mini
        