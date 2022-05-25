#User function Template for python3

class Solution:
    
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,arr,n):
        maxi=float("-inf")
        lis=[1]*(n)
        for i in range(n):
            for j in range(0,i):
                if arr[j]<arr[i]:
                    lis[i]=max(lis[i],lis[j]+1)
            maxi=max(maxi,lis[i])
        return  maxi          
                    
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