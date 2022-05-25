#User function Template for python3
from bisect import bisect_left
class Solution:
    
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,arr,n):
        temp=[arr[0]]
        for i in range(1,n):
            if arr[i]>temp[-1]:
                temp.append(arr[i])
            else:
                index=bisect_left(temp,arr[i])
                temp[index]=arr[i]
        return len(temp)        
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