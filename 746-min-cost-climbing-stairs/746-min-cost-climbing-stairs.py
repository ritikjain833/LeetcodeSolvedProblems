class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        ans=[0]*(n+1)
        for i in range(2,n+1):
            ans[i]=min(cost[i-2]+ans[i-2],ans[i-1]+cost[i-1])
        return ans[-1]    
            
        