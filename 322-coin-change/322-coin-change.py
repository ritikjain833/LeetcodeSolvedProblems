class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n=len(coins)
        dp=[[10**4+1]*(amount+1) for _ in range(n+1)]
        for i in range(0,n+1):
            dp[i][0]=0
        for i in range(1,n+1):
            for j in range(1,amount+1):
                if coins[i-1]<=j:
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]])
                else:
                    dp[i][j]=dp[i-1][j]
        #print(dp)            
        if dp[n][amount]!=(10**4+1):
            return dp[n][amount]
        else:
            return -1
        