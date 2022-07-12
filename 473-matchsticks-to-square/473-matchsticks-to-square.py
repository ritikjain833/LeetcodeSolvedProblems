class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        sum1=sum(matchsticks)
        
        if sum1%4!=0:
            return False
        n=len(matchsticks)
        possible_sum=sum1//4
        matchsticks.sort(reverse=True)
        subsets=[0,0,0,0]
        def dfs(index):
            if index==n:
                return subsets[0]==subsets[1]==subsets[2]==possible_sum
            for i in range(4):
                if matchsticks[index]+subsets[i]<=possible_sum:
                    subsets[i]+=matchsticks[index]
                    if dfs(index+1):
                        return True
                    subsets[i]-=matchsticks[index]
            return False
        return dfs(0)
        
        
        
        