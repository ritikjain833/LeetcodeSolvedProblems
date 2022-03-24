class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n=len(s)
        if n<10:
            return []
        ans=set()
        seen=set()
        
        for i in range(n-9):
            aux=s[i:i+10]
            if aux in seen:
                ans.add(aux)
            else:
                seen.add(aux)
        return list(ans)        
            
        