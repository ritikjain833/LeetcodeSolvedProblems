
class Solution:
    def minSum(self, arr, n):
        # Your code goes here
        arr.sort()
        num1=0
        num2=0
        for i in range(0,n,2):
            num1=num1*10+arr[i]
            if i+1<n:
                num2=num2*10+arr[i+1]
        return num1+num2    
            

#{ 
#  Driver Code Starts

import heapq as hq

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        n = int(input())
        arr = [int(x) for x in input().split()]
        ob=Solution()
        print(ob.minSum(arr,n))

# } Driver Code Ends