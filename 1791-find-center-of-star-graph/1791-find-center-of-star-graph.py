class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        adj=defaultdict(list)
        for i,j in edges:
            adj[i].append(j)
            adj[j].append(i)
        n=len(edges)    
        #print(n)
        for i,j in adj.items():
            #print(i,j)
            if len(j)==n:
                return i
        