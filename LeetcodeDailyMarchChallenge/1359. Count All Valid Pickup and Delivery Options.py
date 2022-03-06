class Solution:
    def countOrders(self, n: int) -> int:
        dp=[0]*(501)
        dp[1]=1
        mod=10**9+7
        for i in range(2,n+1):
            # ways to arrange to pickup point n! for current i
            pickup=dp[i-1]*i
            # ways to arrange the delivery point 2*(i-1) for last one position for second last 3 and so on..
            deliver=pickup*(2*i-1)
            dp[i]=deliver%mod
            
        return dp[n]   
            
            
        
        
