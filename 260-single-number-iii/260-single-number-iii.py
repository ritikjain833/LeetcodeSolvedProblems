# class Solution:
#     def singleNumber(self, nums: List[int]) -> List[int]:
#         dic=Counter(nums)
#         ans=[]
#         for i,j in dic.items():
#             if j==1:
#                 ans.append(i)
#         return ans  
class Solution:
    
    def singleNumber(self,nums: List[int]) -> List[int]:
        xor1=0
        xor2=0
        index=0
        """finding the xor of all elements will result in xor of two unique elements"""
        for i in nums:
            xor1=xor1^i
        # Now for finding the one number we can find the first set bit from the lsb .
        #other will have zero corresponding bit .
        # now xoring all the elements at the corresponding index will result in cancellation of all numbers except one single number that is unique.
        #  find xor with total u will get second element.
        for i in range(32):
            if (xor1&(1<<i)):
                index=i
                break
        for n in nums:
            if(n&(1<<i)):
                xor2=xor2^n
        return [xor2,xor1^xor2]        
                       
        

        
      
        