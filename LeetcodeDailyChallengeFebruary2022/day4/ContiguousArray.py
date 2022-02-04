class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n=len(nums)
        #using hashmap for count if any zero is encountered decrement value by 1 else increment by 1
        #create a dictionary for each of the count  where key is count and value is index
        # if there exist same value of count and then in between there exist same number of zeroes and ones.
        dic=dict()
        dic[0]=-1
        maxlen=0
        count=0
        
        for i in range(n):
            if nums[i]==0:
                count-=1
            else:
                count+=1
            if count in dic:
                maxlen=max(maxlen,i-dic[count])
            else:
                dic[count]=i
        return maxlen        
                
        
            
            
                
            
        
