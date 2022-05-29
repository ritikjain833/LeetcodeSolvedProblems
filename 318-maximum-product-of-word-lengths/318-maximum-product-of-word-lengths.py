class Solution:
    def getstate(self,word):
        mask=0
        word=list(set(word))
        for i in range(len(word)):
            mask|=(1<<(ord(word[i])-ord("a")))
        return mask    
            
        
    def maxProduct(self, words: List[str]) -> int:
        n=len(words)
        state=[0]*(n)
        for i in range(n):
            state[i]=self.getstate(words[i])
        ans=0
        for i in range(n):
            for j in range(i+1,n):
                if (state[i]&state[j])==0:
                    ans=max(ans,len(words[i])*len(words[j]))
        return ans            
        