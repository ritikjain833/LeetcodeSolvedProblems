class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n=len(s)
        ans_len=int(math.pow(2,k))
        seen=[False]*(ans_len)
        aux=s[0:k]
        #print(aux)
        count=0
        ans=0
        while pow(2,n)>=k and count<min(k,n) :
            ans=(ans*2)|int(aux[count])
            count+=1  
        seen[ans]=True 
        val=ans
        
        all_one=ans_len-1
        ans_len-=1
        for i in range(k,n):
            val=((val<<1)&all_one)|(int(s[i]))
            #print(val)
            if seen[val]==False:
                seen[val]=True
                ans_len-=1
                #print(ans_len)
                if ans_len==0:
                    return True
        return False        
                     
            
            
        