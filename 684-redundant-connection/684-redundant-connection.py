#from collections import deque
class Solution:
    def dfs(self,adj,src,target,visited):
        
        visited[src]=True
        if src==target:
            return True
        for nei in adj[src]:
            if visited[nei]==False:
                if self.dfs(adj,nei,target,visited)==True:
                    return True
        return False        
        
            
                
        
        
                
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        """ Check for each edges considering u as src and v as target and then applying dfs to for cycle check
        Time complexity will be O(n*n) because for each edge we have consider the dfs so n*n n^2.        
        
        """
        m=len(edges)
        adj=defaultdict(set)
        
        for i,j in edges:
            # we have to create boolean visited array for each dfs iteration
            visited=[False]*(m+1)
            
            if self.dfs(adj,i,j,visited):
                return i,j
                
                
            adj[i].add(j)
            adj[j].add(i)
            
        