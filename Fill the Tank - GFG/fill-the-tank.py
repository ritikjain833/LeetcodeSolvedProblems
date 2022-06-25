#User function Template for python3

from collections import deque,defaultdict
import sys
sys.setrecursionlimit(10**7)
class Solution:
    def dfs(self,S,adj,Cap,target,parent=None):
        target-=Cap[S-1]
        if target<0:
            return False
        n=len(adj[S])    
        if parent:
            n=n-1
        if n==0:
            return True
        dist=target//n
        for out in adj[S]:
            if out==parent:
                continue
            if not self.dfs(out,adj,Cap,dist,S):
                return False
        return True        
        #n=len(adj[S])
        
                    
                
        
    def minimum_amount (self, Edges, N, S, Cap):
        # code here
        """Graph Constrution"""
        adj=defaultdict(list)
        for i,j in Edges:
            adj[i].append(j)
            adj[j].append(i)
        """DFS approach"""
        #C=[0]+Cap
        low=1
        high=10**18+1
        while low<high:
            mid=low+(high-low)//2
            ans=self.dfs(S,adj,Cap,mid)
            if ans:
                high=mid
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