class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n=len(nums)
        temp=[0]*(n)
        i=0
        j=1
        for aux in nums:
            if aux>0:
                temp[i]=aux
                i+=2
            else:
                temp[j]=aux
                j+=2
        return temp        
               
                
                
            
        
