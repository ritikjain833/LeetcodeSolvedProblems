class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        diff=0
        for i in range(len(s)):
            diff-=ord(s[i])
            diff+=ord(t[i])
        diff+=ord(t[len(s)])
        return chr(diff)
                
        
