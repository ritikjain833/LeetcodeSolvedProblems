class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=1
        n=len(nums)
        if n==1:
            return nums[0]
        #initializing the value of the major to the first element of the array.  
        major=nums[0]
        
        for i in range(1,n):
          # if number is found as same as major then increment the count value
            if nums[i]==major:
                count+=1
            else:
            #else decrement the count  
                count-=1
              # if count==0 then we have found that major is not majority element change to the next element
                if count==0:
                    major=nums[i]
                    count=1
        return major            
        
        
