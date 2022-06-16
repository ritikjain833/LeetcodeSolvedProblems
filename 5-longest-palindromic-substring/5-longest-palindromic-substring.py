""" Brute solution
time complexity is O(n^3) because time to calculate all substrings is O(n^2) and check palindrome is O(n). so total it is O(n^3). 
class Solution:
    def checkPalindrome(self,s,i,j):
        while i<j:
            if s[i]!=s[j]:
                return False
            else:
                i+=1
                j-=1
        return True    
    def longestPalindrome(self, s: str) -> str:
        ans=float("-inf")
        #print(1)
        res=""
        for i in range(len(s)):
            aux=""
            #print(aux)
            for j in range(i,len(s)):
                aux+=s[j]
                #print(aux)
                if self.checkPalindrome(s,i,j)==True:
                    if j-i+1>ans:
                        res=s[i:j+1]
                        ans=max(ans,j-i+1)
        #print(res)
        return res
"""  
""" O(n^2) and O(n^2)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        dp=[[False]*(n) for _ in range(n)]
        ans=""
        max1=0
        for j in range(n):
            for i in range(j+1):
                temp=(s[i]==s[j])
                if j-i>=2:
                    dp[i][j]=dp[i+1][j-1] and temp
                else:
                    dp[i][j]=temp
                if dp[i][j] and j-i+1>max1:
                    max1=j-i+1
                    ans=s[i:j+1]
        return ans  
        
"""   
class Solution:
    def expand(self,s,start,end):
        while start>=0 and end<len(s) and s[start]==s[end]:
            start-=1
            end+=1
        return start,end
            
        
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        ans=0
        res=""
        for i in range(n):
            l1,r1=self.expand(s,i,i)  
            if r1-l1-1>ans:
                ans=r1-l1-1
                res=s[l1+1:r1]
            l2,r2=self.expand(s,i,i+1)
            if r2-l2-1>ans:
                ans=r2-l2-1
                res=s[l2+1:r2]
                
    
        return res        
                
            
    
        
                
        