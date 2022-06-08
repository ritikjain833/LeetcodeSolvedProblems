#Kruskal Algorithm O(n^2 logn )
# class DSU:
#     def __init__(self,n):
#         self.rank=[1 for i in range(n)]
#         self.parent=[i for i in range(n)]
#     def find(self,a):
#         if a==self.parent[a]:
#             return a
#         else:
#             self.parent[a]=self.find(self.parent[a])
#             return self.parent[a]
#     def union(self,a,b):
#         parent_a=self.find(a)
#         parent_b=self.find(b)
#         if parent_a==parent_b:
#             self.rank[parent_b]=parent_a
#             self.parent[parent_a]+=1
#         if self.rank[parent_a]>self.rank[parent_b]:
#             self.parent[parent_b]=parent_a
#             self.rank[parent_a]+=1
#         else:
#             self.parent[parent_a]=parent_b
#             self.rank[parent_b]+=1
            
# class Solution:
#     def minCostConnectPoints(self, points: List[List[int]]) -> int:
#         n=len(points)
#         edges=[]
#         for i in range(n):
#             for j in range(i+1,n):
#                 distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])
#                 edges.append((distance,i,j))
#         edges.sort()
#         res=0
#         ds=DSU(n)
#         count=0
#         for cost,i,j in edges:
#             if ds.find(i)!=ds.find(j):
#                 res+=cost
#                 count+=1
#                 ds.union(i,j)
#                 if count==n-1:
#                     break
#         return res 
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:  
        n=len(points)
        heap=[(0,0)]
        mstSet=[False]*(n)
        mst_cost=0
        edges_used=0
        while edges_used<n:
            w,u=heapq.heappop(heap)
            if mstSet[u]:
                continue
            mstSet[u]=True
            
            mst_cost+=w
            edges_used+=1
            for next_node in range(n):
                if not mstSet[next_node]:
                    next_w=abs(points[u][0]-points[next_node][0])+abs(points[u][1]-points[next_node][1])
                    heapq.heappush(heap,(next_w,next_node))
        return mst_cost           
    
    
                
        