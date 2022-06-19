class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        i=0
        j=0
        m=len(nums1)
        n=len(nums2)
        ans=0
        while i<m and j<n:
            if nums2[j]>=nums1[i]:
                ans=max(j-i,ans)
                j+=1
            else:
                i+=1
        return ans        
                
        