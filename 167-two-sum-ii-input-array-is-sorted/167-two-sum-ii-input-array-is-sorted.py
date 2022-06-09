class Solution:
    def binary_search(self,target,arr,start,end):
        while start<=end:
            mid=(start+end)//2
            #print(arr[mid],target)
            if arr[mid]==target:
                return mid,True
            elif arr[mid]>target:
                end=mid-1
            else:
                start=mid+1
        return -1,False        
        
        
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        end=len(nums)-1
        for i in range(len(nums)):
            new_target=target-nums[i]
            index,flag=self.binary_search(new_target,nums,i+1,end)
            if flag==True:
                return [i+1,index+1]
    
                
        