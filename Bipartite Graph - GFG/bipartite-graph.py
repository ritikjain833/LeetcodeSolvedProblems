
from collections import deque

class Solution:
    def bfs(self,src,queue,color,visited,adj):
        color[src]=1
        visited[src]=True
        queue.append(src)
        while queue:
	        aux=queue.popleft()
	        for i in adj[aux]:
	            if color[i]==-1:
	                color[i]=1-color[aux]
	                queue.append(i)
	                visited[i]=True
	            elif color[i]==color[aux]:
	                return False
	    return True
        
	def isBipartite(self, V, adj):
	    queue=deque()
	    #queue.append(0)
	    color=[-1]*(V)
	    visited=[False]*(V)
	    #visited[0]=True
	    
	    for i in range(V):
	        if visited[i]==False:
	            if self.bfs(i,queue,color,visited,adj)==False:
	                return False
	    return True            
	                 
	                
	    
		#code here

#{ 
#  Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().strip().split())
		adj = [[] for i in range(V)]
		for i in range(E):
			u, v = map(int, input().strip().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.isBipartite(V, adj)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends