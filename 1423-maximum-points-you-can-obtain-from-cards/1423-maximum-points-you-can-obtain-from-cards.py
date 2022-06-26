class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n=len(cardPoints)
        prefix=[0]*(n+1)
        #prefix[0]=cardPoints[0]
        for i in range(1,n+1):
            prefix[i]=prefix[i-1]+cardPoints[i-1]
        #print(prefix)    
        mini=float("inf")    
        for i in range(k+1):
            mini=min(mini,(prefix[i+(n-k)]-prefix[i]))
        return prefix[-1]-mini    
            
            
        