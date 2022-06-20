#User function Template for python3

class Solution:
    def fact(self,n):
 
        res = 1
         
        for i in range(2, n+1):
            res = res * i
             
        return res
    def nCr(self,n, r):
 
        return (self.fact(n) / (self.fact(r)
                    * self.fact(n - r)))
    def posIntSol(self,s):
        #code here
        count=0
        variables=[]
        target=0
        x="abcdefghijklmnopqrstuvwxyz"
        for i in range(len(s)):
            if s[i] in x:
                variables.append((s[i]))
            elif s[i]=="+" or s[i]=="=":
                continue
            elif s[i].isdigit():
                target=target*10+int(s[i])
                
        matter=len(variables)
        #print(target,matter)
        return int(self.nCr(target-1,matter-1))

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.posIntSol(s))
# } Driver Code Ends