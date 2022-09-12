class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        count=0
        ans=0
        i=0
        j=len(tokens)-1
        while i<=j:
            if power>=tokens[i]:
                count+=1
                ans=max(count,ans)
                power-=tokens[i]
                i+=1
            else:
                if count>=1:
                    count-=1
                    power+=tokens[j]
                j-=1
                
           
        return ans        
        