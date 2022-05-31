class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n=len(s)
        ans_len=(math.pow(2,k))
        seen=set()
        for i in range(n-k+1):
            temp=s[i:i+k]
            if temp not in seen:
                seen.add(temp)
                ans_len-=1
                if ans_len==0:
                    return True
        return False        
            
            
        