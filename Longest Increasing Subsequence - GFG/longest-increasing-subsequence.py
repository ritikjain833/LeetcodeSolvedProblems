#User function Template for python3

class Solution:
    
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,arr,n):
        arr2=sorted(list(set(arr)))
        m=len(arr2)
        dp=[[0]*(m+1) for _ in range(n+1)]
        for i in range(n+1):
            for j in range(m+1):
                if i>0 and j>0:
                    if arr[i-1]==arr2[j-1]:
                        dp[i][j]=1+dp[i-1][j-1]
                    else:
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        return dp[-1][-1]            
                
        # code here
       


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = [ int(x) for x in input().split() ]
        ob=Solution()
        print(ob.longestSubsequence(a,n))
# } Driver Code Ends