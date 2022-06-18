class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        # store the current sum in the sum1 variable
        sum1=0
        sum2=0
        i=0
        j=0
        m=len(nums1)
        n=len(nums2)
        #used the give final answer
        # two pointer approach is used
        ans=0
        while i<m and j<n:
            
            #if one is less than other sum the current sum in their repsective sum variable
            if nums1[i]<nums2[j]:
                sum1+=nums1[i]
                i+=1
            elif nums1[i]>nums2[j]:
                sum2+=nums2[j]
                j+=1
            # find the intersection point of both the arrays.
            
            else:
                ans+=nums1[i]+max(sum1,sum2)
                i+=1
                j+=1
                sum1=0
                sum2=0
        while i<m:
            sum1+=nums1[i]
            i+=1
        while j<n:
            sum2+=nums2[j]
            j+=1
        ans=ans+max(sum1,sum2)
        mod=10**9+7
        return ans%mod
            
        