#User function Template for python3
class Solution:
	def minOperations(self, s1, s2):
		# code here
		m=len(s1)
		n=len(s2)
		dp=[[0]*(n+1) for _ in range(m+1)]
		for i in range(1,m+1):
		    for j in range(1,n+1):
		        if s1[i-1]==s2[j-1]:
		            dp[i][j]=1+dp[i-1][j-1]
		        else:
		            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
		lcs=dp[m][n]
		return m+n-2*lcs

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s1,s2 = input().split()
		ob = Solution()
		ans = ob.minOperations(s1,s2)
		print(ans)
# } Driver Code Ends