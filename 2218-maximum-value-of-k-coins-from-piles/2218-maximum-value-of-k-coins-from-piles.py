class Solution:
    def solve(self,dp,piles,index, k):
        if k==0 or index>=len(piles):
            return 0
        if dp[index][k]!=-1:
            return dp[index][k]
        res=self.solve(dp,piles,index+1,k)
        cur=0
        for j in range(min(len(piles[index]),k)):
            cur+=piles[index][j]
            #print(cur)
            res=max(res,cur+self.solve(dp,piles,index+1,k-j-1))
        dp[index][k]=res
        #print(dp[index][k])
        return dp[index][k]
        
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n=len(piles)
        dp=[[-1]*(k+1) for _ in range(n+1)]
        return self.solve(dp,piles,0,k)
        