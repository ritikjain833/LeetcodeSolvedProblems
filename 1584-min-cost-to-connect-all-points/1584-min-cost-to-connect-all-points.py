class DSU:
    def __init__(self,n):
        self.rank=[1 for i in range(n)]
        self.parent=[i for i in range(n)]
    def find(self,a):
        if a==self.parent[a]:
            return a
        else:
            self.parent[a]=self.find(self.parent[a])
            return self.parent[a]
    def union(self,a,b):
        parent_a=self.find(a)
        parent_b=self.find(b)
        if parent_a==parent_b:
            self.rank[parent_b]=parent_a
            self.parent[parent_a]+=1
        if self.rank[parent_a]>self.rank[parent_b]:
            self.parent[parent_b]=parent_a
            self.rank[parent_a]+=1
        else:
            self.parent[parent_a]=parent_b
            self.rank[parent_b]+=1
            
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        edges=[]
        for i in range(n):
            for j in range(i+1,n):
                distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])
                edges.append((distance,i,j))
        edges.sort()
        res=0
        ds=DSU(n)
        count=0
        for cost,i,j in edges:
            if ds.find(i)!=ds.find(j):
                res+=cost
                count+=1
                ds.union(i,j)
                if count==n-1:
                    break
        return res        
                
        