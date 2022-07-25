class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def last(nums,target):
            index1=0
            low=0
            high=len(nums)-1
            while(low<=high):
                mid=low+(high-low)//2
                if nums[mid]<=target:
                    low=mid+1
                    index1=mid
                    
                    
                else:
                    high=mid-1
            if len(nums)==0 or nums[index1]!=target:
                return -1
            else:
                return index1
        def first(nums,target):
            
            low=0
            index=0
            high=len(nums)-1
            while(low<high):
                mid=low+(high-low)//2
                if nums[mid]>=target:
                    high=mid
                else:
                    low=mid+1
                    index=low
            if len(nums)==0 or nums[index]!=target :
                return -1
            else:
                return index
        a=[-1,-1]    
        a[0]=first(nums,target)
        a[1]=last(nums,target)
        return a
        
        
            
        