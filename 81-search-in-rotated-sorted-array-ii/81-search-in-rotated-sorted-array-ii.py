class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        low=0
        high=len(nums)-1
        while low<=high:
            mid=(low+high)//2
            #print(low,high,mid)
            if nums[mid]==target:
                return True
            # for cases like 1 0 1 1 1 here nums[mid]==nums[low] so our increasing order is not maintained but nums[right] will also be equal to nums[mid]
            if nums[low]==nums[mid] and nums[mid]==nums[high]:
                low+=1
                high-=1
            elif nums[mid]>=nums[low]:
                if target>=nums[low] and target<nums[mid]:
                    high=mid-1
                else:
                    low=mid+1
            else:
                if nums[mid]<target and target<nums[low]:
                    low=mid+1
                else:
                    high=mid-1
        return False
