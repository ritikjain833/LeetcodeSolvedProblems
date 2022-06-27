from collections import deque
class Solution:
    """DFS approach is used to finding the ordering of topological sort"""
    def dfs(self,i,adj,ans,visited):
        visited[i]=True
        #ans.append(i)
        for out in adj[i]:
            if visited[out]==False:
                self.dfs(out,adj,ans,visited)
               
        ans.append(i)        
        
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        # visited=[False]*(V)
        # ans=[]
        # for i in range(V):
        #     if visited[i]==False:
        #         self.dfs(i,adj,ans,visited)
        # return ans[::-1] 
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
        return ans                
                        
                        
                


#{ 
#  Driver Code Starts
# Driver Program

import sys
sys.setrecursionlimit(10**6)
        
def check(graph, N, res):
    if N!=len(res):
        return False
    map=[0]*N
    for i in range(N):
        map[res[i]]=i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        e,N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]
        
        for i in range(e):
            u,v=map(int,input().split())
            adj[u].append(v)
            
        ob = Solution()
        
        res = ob.topoSort(N, adj)
        
        if check(adj, N, res):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends