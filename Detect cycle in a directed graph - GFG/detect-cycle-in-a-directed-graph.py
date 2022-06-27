#User function Template for python3
from collections import deque
"""DFS Approach for cycle detection using the recursive_Stack if node is alreday present in the stack then that means cycle is detected"""
class Solution:
    def dfs(self,i,visited,rec_stack,adj):
        visited[i]=True
        rec_stack[i]=True
        for nei in adj[i]:
            if visited[nei]==False:
                if self.dfs(nei,visited,rec_stack,adj):
                    return True
            elif rec_stack[nei]==True:
                return True
        rec_stack[i]=False
        return False
        
                    
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V, adj):
        
        # code here
        # visited=[False]*(V)
        # rec_stack=[False]*(V)
        # for i in range(V):
        #     if visited[i]==False:
        #         if self.dfs(i,visited,rec_stack,adj):
        #             return True
        # return False 
        """Kahn's algorithm to find topological sort"""
         
        degree=[0]*(V)
        
        for i in range(V):
            for j in adj[i]:
                degree[j]+=1
        queue=deque()
        ans=[]
        visited=[False]*(V)
        for i in range(V):
            if degree[i]==0:
                queue.append(i)
                ans.append(i)
                visited[i]=True
                
        while queue:
            aux=queue.popleft()
            for out in adj[aux]:
                if visited[out]==False:
                    degree[out]-=1
                    if degree[out]==0:
                        queue.append(out)
                        ans.append(out)
        if len(ans)==V:
            return False
        else:
            return True

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)
        
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
        ob = Solution()
        
        if ob.isCyclic(V, adj):
            print(1)
        else:
            print(0)
# } Driver Code Ends