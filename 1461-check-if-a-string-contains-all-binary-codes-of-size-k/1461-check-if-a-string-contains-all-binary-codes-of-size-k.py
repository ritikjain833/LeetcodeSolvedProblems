class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n=len(s)
        ans_len=int(math.pow(2,k))
        seen=[False]*(ans_len)
        val=0
        all_one=ans_len-1
        for i in range(n):
            val=((val<<1)&all_one)|(int(s[i]))
            if i>=k-1 and seen[val]==False:
                seen[val]=True
                ans_len-=1
                if ans_len==0:
                    return True
        return False        
                     
            
            
        