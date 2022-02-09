class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        dic=Counter(nums)
        if k==0:
            count=0
            for val in dic.values():
                count+=(val>=2)
            return count
        ans=set()
        for n in nums:
            #if n-k is also present in the dictionary n-a=k  // a=n-k
            if n-k in dic:
                #store them in a particular order either increasing or decreasing order
                if n>n-k:
                    ans.add((n,n-k))
                else:
                    ans.add((n-k,n))
            #if n+k is also present in  the dictionary n-a=-k // a=n+k         
            if n+k in dic:
                #store them in a particular order either increasing or decreasing order
                if n>n+k:
                    ans.add((n,n+k))
                else:    
                    ans.add((n+k,n))  
        #length of the set is tells the final answer            
        return len(ans)
                
