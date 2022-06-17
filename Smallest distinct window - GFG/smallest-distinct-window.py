#User function Template for python3

class Solution:
    def findSubString(self, str):
        # Your code goes here
        target=len(set(str))
        n=len(str)
        start=0
        end=0
        visited=dict()
        mini=float('inf')
        count=0
        while end<n:
            visited[str[end]]=visited.get(str[end],0)+1
            while visited[str[start]]>1:
                visited[str[start]]-=1
                start+=1
            if len(visited)==target:
                mini=min(mini,end-start+1)
            end+=1    
                    
                
            
        return mini    
                
            
            
    
    
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while(T > 0):
    	str = input()
    	ob=Solution()
    	print(ob.findSubString(str))
    	
    	T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends