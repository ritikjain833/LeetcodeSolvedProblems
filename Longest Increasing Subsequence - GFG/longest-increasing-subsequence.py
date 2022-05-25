#User function Template for python3
from bisect import bisect_left
class Solution:
    
    def binary_search(self,temp,target):
        l=0
        r=len(temp)-1
        while l<r:
            mid=(l+r)//2
            if temp[mid]>target:
                r=mid
            else:
                l=mid+1
        return l        
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,arr,n):
        temp=[arr[0]]
        for i in range(1,n):
            if arr[i]>temp[-1]:
                temp.append(arr[i])
            else:
                index=self.binary_search(temp,arr[i])
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