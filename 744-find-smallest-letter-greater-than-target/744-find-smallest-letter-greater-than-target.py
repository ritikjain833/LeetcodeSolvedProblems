class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        low=0
        high=len(letters)-1
        while low<=high:
            mid=(low+high)//2
            if letters[mid]<=target:
                low=mid+1
            else:
                high=mid-1
        return letters[low%len(letters)]        
            
        