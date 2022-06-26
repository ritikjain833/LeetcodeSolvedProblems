class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        total_sum=0
        n=len(cardPoints)
        for c in cardPoints:
            total_sum+=c
        prefix=[0]*(n+1)
        prefix[0]=cardPoints[0]
        for i in range(1,n+1):
            prefix[i]=prefix[i-1]+cardPoints[i-1]
        #print(prefix)    
        maxi=float("-inf")    
        for i in range(k+1):
            maxi=max(maxi,total_sum-(prefix[i+(n-k)]-prefix[i]))
        return maxi    
            
            
        