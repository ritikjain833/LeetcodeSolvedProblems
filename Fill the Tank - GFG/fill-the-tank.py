#User function Template for python3

from collections import deque,defaultdict
import sys
sys.setrecursionlimit(10**7)
class Solution:
    def dfs(self,S,adj,Cap,target,parent=None):
        target-=Cap[S-1]
        # if target is less than zero we cannot fill in that case.
        if target<0:
            return False
        n=len(adj[S])   
        # leaving the source node
        if parent:
            n=n-1
        #leaf node termination    
        if n==0:
            return True
        #finding the remaining water    
        dist=target//n
        for out in adj[S]:
            if out==parent:
                continue
            if not self.dfs(out,adj,Cap,dist,S):
                return False
        return True        
        #n=len(adj[S])
    def bfs(self,S,adj,Cap,target):
        visited=[False]*(N+1)
        visited[S]=True
        queue=deque()
        queue.append((S,target))
        while queue:
            aux,remain=queue.popleft()
            remain-=Cap[aux-1]
            #print(aux,remain)
            if remain<0:
                #print("I am here")
                return False
            n=len(adj[aux])
            if aux!=S:    
                n=n-1  
            if n==0:
                continue
            left=remain//n
            for out in adj[aux]:
                if aux==out:
                    continue
                if visited[out]==False:
                    queue.append((out,left))
                    #print(out,left)
                    visited[out]=True
        return True    
        
                    
                
        
    def minimum_amount (self, Edges, N, S, Cap):
        # code here
        """Graph Constrution"""
        adj=defaultdict(list)
        for i,j in Edges:
            adj[i].append(j)
            adj[j].append(i)
        """DFS approach"""
        #C=[0]+Cap
        #minimum Cap required is Sum(Cap)
        low=sum(Cap)
        high=10**18+1
        while low<high:
            mid=low+(high-low)//2
            ans=self.dfs(S,adj,Cap,mid)
            #print(mid,ans)
            # if ans is possible atcan be upto this so use high=mid
            if ans:
                high=mid
            #if ans is not possible just increase the low=mid+1    
            else:
                low=mid+1
        if low>10**18:
            return -1
        return low
            
            
                


#{ 
#  Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        N, S = map(int,input().split())
        Cap = list(map(int, input().split()))
        Edges = list()
        for i in range(0, N-1):
            L = list(map(int, input().split()))
            Edges.append(L)
        ans = ob.minimum_amount(Edges, N, S, Cap);
        print(ans)




# } Driver Code Ends