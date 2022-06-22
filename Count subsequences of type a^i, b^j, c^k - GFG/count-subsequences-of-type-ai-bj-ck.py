#User function Template for python3

class Solution:
    def fun(self,s):
        count_a=0
        count_ab=0
        count_abc=0
        mod=10**9+7
        for ch in s:
            if ch=="a":
                count_a=(2*count_a+1)%mod
            elif ch=="b":
                count_ab=(2*count_ab+count_a)%mod
            elif ch=="c":
                count_abc=(2*count_abc+count_ab)%mod
        return count_abc%mod        
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#Position this line where user code will be pasted.

t=int(input())
for _ in range(t):
    s=input()
    print(Solution().fun(s))
# } Driver Code Ends