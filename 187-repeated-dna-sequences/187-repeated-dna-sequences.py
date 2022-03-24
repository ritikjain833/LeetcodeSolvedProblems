class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n=len(s)
        if n<10:
            return []
        ans=set()
        seen=set()
        l=0
        
        for r in range(9,n):
            aux=s[l:r+1]
            if aux in seen:
                ans.add(aux)
            else:
                seen.add(aux)
            l+=1    
        return list(ans)        
            
        