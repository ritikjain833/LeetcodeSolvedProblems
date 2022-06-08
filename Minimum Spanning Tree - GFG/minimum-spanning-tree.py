#User function Template for python3
from collections import defaultdict
class Solution:
    def min_key(self,key,mstSet):
        mini=sys.maxsize
        index=0
        for i in range(len(key)):
            if key[i]<mini and mstSet[i]==False:
                mini=key[i]
                index=i
        return index        
        
    
    #Function to find sum of weights of edges of the Minimum Spanning Tree.
    def spanningTree(self, V, adj):
        key=[sys.maxsize]*(V)
        key[0]=0
        mstSet=[False]*(V)
        #print(adj)
        #code here
        graph=[[0]*(V) for _ in range(V)]
        for i in range(V):
            for j in range(len(adj[i])):
                graph[i][adj[i][j][0]]=adj[i][j][1]
        #print(graph)        
        count=0
        parent=[None]*(V)
        parent[0]=-1
        while count<V:
            u=self.min_key(key,mstSet)
            mstSet[u]=True
            for v in range(V):
                if graph[u][v]>0 and mstSet[v]==False and key[v]>graph[u][v]:
                    key[v]=graph[u][v]
                    parent[v]=u
            count+=1        
        ans=0            
        for i in range(1,V):
            ans+=graph[i][parent[i]]
        return ans    
            
                
            
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V,E = map(int,input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u,v,w = map(int,input().strip().split())
            adj[u].append([v,w])
            adj[v].append([u,w])
        ob = Solution()
        
        print(ob.spanningTree(V,adj))
# } Driver Code Ends