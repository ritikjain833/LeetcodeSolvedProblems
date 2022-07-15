class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=0
        j=0
        m=len(s)
        n=len(t)
        while i<m and j<n:
            
            
            if s[i]==t[j]:
                i+=1
                j+=1
            else:
                j+=1
        if i==m:
            return True
        else:
            return False
                    
        