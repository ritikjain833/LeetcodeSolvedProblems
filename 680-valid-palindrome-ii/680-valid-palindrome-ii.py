class Solution:
    def reverse1(self,s,i,j):
        while i<j:
            if s[i]!=s[j]:
                return False
            i+=1
            j-=1
        return True    
    def validPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                
                return self.reverse1(s,i,j-1) or self.reverse1(s,i+1,j)
                
            i+=1
            j-=1
        return True