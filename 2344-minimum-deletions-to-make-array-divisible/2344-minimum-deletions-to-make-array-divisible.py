class Solution:
    def find_gcd(self,a,b):
        while b:
            a,b=b,a%b
        return a    

    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        n=len(numsDivide)
        gcd=0
        if n>1:
            gcd=self.find_gcd(numsDivide[0],numsDivide[1])
            for i in range(2,n):
                gcd=self.find_gcd(gcd,numsDivide[i])
        else:
            gcd=numsDivide[0]
        nums.sort()
        ans=0
        for i in range(len(nums)):
            if gcd%nums[i]==0:
                return ans
            else:
                ans+=1
        return -1
        
        
        
        