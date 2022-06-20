class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count=0
        check=[0]*(26)
        for c in allowed:
            check[ord(c) -ord("a")]+=1
        for word in words:
            
            characters=[0]*(26)
            for i in word:
                characters[ord(i)-ord("a")]+=1
            flag=False    
            for i in range(26):
                if characters[i]>=1 and check[i]==0:
                    flag=False
                    break
                else:
                    flag=True
            if flag==True:
                count+=1
        return count            
                    
                        
        