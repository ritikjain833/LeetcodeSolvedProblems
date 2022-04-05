class Solution:
    def maxArea(self, height: List[int]) -> int:
        i=0
        j=len(height)-1
        area=float("-inf")
        while i<j:
            height1=height[i]
            height2=height[j]
            if height[i]<height[j]:
                area=max(height[i]*(j-i),area)
                i+=1
            else:
                area=max(area,height[j]*(j-i))
                j-=1
        return area        
            
            
        