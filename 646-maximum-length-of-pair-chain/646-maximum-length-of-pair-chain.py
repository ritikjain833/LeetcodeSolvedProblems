class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x:x[1])
        count=0
        #n=len(pairs)
        prev=float("-inf")
        for i,j in pairs:
            if prev<i:
                count+=1
                prev=j
        return count        
            
        