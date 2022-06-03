#User function Template for python3

class Solution:
    def isPossible(self, S, N, X, A):
        # code here
        s=S
        idx=N
        for i in range(N):
            A[i]=S+A[i]
            S=S+A[i]
            if S>X:
                idx=i
                break
        while X>=0 and idx>=0:
            if X>=A[idx]:
                X-=A[idx]
            if X==0 or X-s==0:
                return True
            idx-=1    
        return False        
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S, N, X = [int(y) for y in input().split()]
        A = input().split()
        for i in range(N):
            A[i] = int(A[i])
        
        ob = Solution()
        if ob.isPossible(S, N, X, A) == 1:
            print("yes")
        else:
            print("no")
# } Driver Code Ends