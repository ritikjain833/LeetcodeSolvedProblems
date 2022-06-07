#User function Template for python3


class Solution:
    def find_parent(self,a):
        if a==par[a]:
            return a
        else:
            par[a]=self.find_parent(par[a])
            return par[a]
    
    #Function to merge two nodes a and b.
    def union_(self,a,b,par,rank):
        # code here
        a=self.find_parent(a)
        b=self.find_parent(b)
        if rank[a]<rank[b]:
            par[a]=b
        elif rank[a]>rank[b]:
            par[b]=a
        else:
            par[a]=b
            rank[b]+=1
        
        
    #Function to check whether 2 nodes are connected or not.
    def isConnected(self,x,y,par,rank1):
        # code here
        if self.find_parent(x)!=self.find_parent(y):
            return 0
        else:
            return 1
#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        q = int(input())

        par = [i for i in range(n+1)] # parent of ith node is initialized as i.
        rank1 = [1 for i in range(n+1)] # rank is initialized as 1 fo every node
        obj = Solution()
        for i in range(q):
            task,u,v = map(str,input().strip().split())
            u = int(u)
            v = int(v)

            if task == 'U':
                obj.union_(u,v,par,rank1)
            else:
                if obj.isConnected(u,v,par,rank1):
                    print(1)
                else:
                    print(0)


# } Driver Code Ends