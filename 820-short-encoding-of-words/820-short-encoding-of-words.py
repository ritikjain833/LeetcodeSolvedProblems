class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        check=set()
        suffix=""
        ans=set(words)
        for word in words:
            suffix=""
            for char in range(len(word)-1,0,-1):
                suffix+=word[char]
                reverse=suffix[::-1]
                if reverse in ans:
                    ans.remove(reverse)
        count=0
        for val in ans:
            count+=(len(val)+1)
        return count    
                    
            
        