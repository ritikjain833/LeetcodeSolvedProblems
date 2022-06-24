#User function Template for python3

class Solution:
    def profession(self, level, pos):
        # code here
        flag=0
        while pos!=1:
            if pos%2==0:
                flag=1-flag
            pos=(pos+1)//2
        if flag==1:
            return 'd'
        else:
            return 'e'

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        level, pos = [int(x) for x in input().split()]
        
        ob = Solution()
        if(ob.profession(level, pos) == 'd'):
            print("Doctor")
        else:
            print("Engineer")
# } Driver Code Ends