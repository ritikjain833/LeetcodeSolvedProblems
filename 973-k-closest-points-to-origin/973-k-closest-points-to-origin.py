class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        ans=[]
        n=len(points)
        for i in range(n):
            ans.append([points[i][0],points[i][1],points[i][0]**2+points[i][1]**2])
        ans.sort(key=lambda x:x[2])
        aux=[]
        for i in range(k):
            aux.append([ans[i][0],ans[i][1]])
        return aux    
        