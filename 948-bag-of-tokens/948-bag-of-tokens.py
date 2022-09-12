class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        #sort tokens in ascending order
        tokens.sort()
        #current_count
        count=0
        ans=0
        #use two pointer approach to solve this problem
        i=0
        j=len(tokens)-1
        #if current_power is more than tokens[i] it is greedier to collect that and move forware
        
        while i<=j:
            if power>=tokens[i]:
                count+=1
                ans=max(count,ans)
                power-=tokens[i]
                i+=1
            #if not then we have two cases when count>=1 we can decrease and shrink the window or we can't do anything and just return ans    
            else:
                if count>=1:
                    count-=1
                    power+=tokens[j]
                    j-=1
                else:
                    return ans
                
           
        return ans        
        