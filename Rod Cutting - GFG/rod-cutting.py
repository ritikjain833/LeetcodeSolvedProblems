#User function Template for python3

class Solution:
    def cutRod(self, price, n):
        #code here
        val=[i for i in range(1,n+1)]
        dp=[[0]*(n+1) for _ in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,n+1):
                if val[i-1]<=j:
                    dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-val[i-1]])
                else:
                    dp[i][j]=dp[i-1][j]
        #print(dp)            
        return dp[n][n]            

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.cutRod(a, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends