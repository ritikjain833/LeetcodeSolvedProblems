class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        ans={}
        m=len(mat)
        n=len(mat[0])
        for r in range(m):
            count=0
            for c in range(n):
                if mat[r][c]==1:
                    count+=1
            ans[r]=count
        ans={k: v for k, v in sorted(ans.items(), key=lambda item: item[1])}   
        res=[]
        count=0
        for key,val in ans.items():
            res.append(key)
            count+=1
            if count==k:
                break
        return res        
            
           
                
        