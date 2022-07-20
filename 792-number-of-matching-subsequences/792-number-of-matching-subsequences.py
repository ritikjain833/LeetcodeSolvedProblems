class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        # Brute force approach TLE
        # count=0
        # n=len(words)
        # m=len(s)
        # for i in range(n):
        #     sub=words[i]
        #     j=0
        #     k=0
        #     l=len(words[i])
        #     temp=0
        #     while j<l and k<m:
        #         if sub[j]==s[k]:
        #             k+=1
        #             j+=1
        #             temp+=1
        #         else:
        #             k+=1
        #     if temp==len(sub):
        #         count+=1
        # return count   
        word_dict=defaultdict(list)
        for word in words:
            word_dict[word[0]].append(word)
        count=0
        for st in s:
            words_starting=word_dict[st]
            word_dict[st]=[]
            for word in words_starting:
                if len(word)==1:
                    count+=1
                else:    
                    word_dict[word[1]].append(word[1:])
        return count        
        
        
                
            
            
        