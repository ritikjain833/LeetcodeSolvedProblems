class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        def count(word):
            ans=[0]*(26)
            for c in word:
                ans[ord(c)-ord('a')]+=1
            return ans
        ans=[]
        b_max=[0]*(26)
        for word in words2:
            ls=count(word)
            for i in range(26):
                b_max[i]=max(b_max[i],ls[i])
        for word in words1:
            ls=count(word)
            for i in range(26):
                if ls[i]<b_max[i]:
                    break
            else:
                ans.append(word)
        return ans        
            
        