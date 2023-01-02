class Solution:
    def allCapital(self,word):
        n=len(word)
        for i in range(n):
            if ord(word[i])>=65 and ord(word[i])<=90:
                continue
            else:
                return False
        return True
    def notCapital(self,word):
        n=len(word)
        for i in range(n):
            if ord(word[i])>=97 and ord(word[i])<=122:
                continue
            else:
                return False
        return True
    def firstCapital(self,word):
        n=len(word)
        temp=False
        for i in range(n):
            if i==0 and ord(word[i])>=65 and ord(word[i])<=90:
                temp=True
            elif i>=0 and ord(word[i])>=65 and ord(word[i])<=90:
                temp=False
                break        
        return temp        
                
        
    def detectCapitalUse(self, word: str) -> bool:
        return self.allCapital(word) or self.notCapital(word) or self.firstCapital(word)
        