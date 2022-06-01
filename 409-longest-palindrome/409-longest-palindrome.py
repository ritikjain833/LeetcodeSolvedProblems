class Solution:
    def longestPalindrome(self, s: str) -> int:
        aux=Counter(s)
        odd_count=0
        for i,j in aux.items():
            if j%2==1:
                odd_count+=1
      
        return len(s)-odd_count+bool(odd_count)      
        