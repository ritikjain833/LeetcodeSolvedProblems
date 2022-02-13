class Solution:
    def dfs(self,index,nums):
        if index==self.n:
            self.res.append(self.temp.copy())
            return
        self.temp.append(nums[index])
        self.dfs(index+1,nums)
        self.temp.pop(-1)
        self.dfs(index+1,nums)
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.temp=[]
        self.res=[]
        # idea is to use the concept of recursion with backtracking 
        self.n=len(nums)
        self.dfs(0,nums)
        return self.res
