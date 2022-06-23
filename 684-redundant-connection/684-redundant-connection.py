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
        m=len(edges)
        adj=defaultdict(set)
        
        for i,j in edges:
            visited=[False]*(m+1)
            if i in adj and j in adj and self.dfs(adj,i,j,visited):
                return i,j
                
                
            adj[i].add(j)
            adj[j].add(i)
            
        