#User function Template for python3

class Solution:
	def TotalWays(self, N):
		# Code here
		if N==1:
		    return 4
		dp=[0]*(N+1)
		dp[1]=2
		dp[2]=3
		mod=10**9+7
		for i in range(3,N+1):
		    dp[i]=(dp[i-1]+dp[i-2])%mod
		return (dp[N]*dp[N])%mod    

#{ 
#  Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.TotalWays(N)
		print(ans)
# } Driver Code Ends