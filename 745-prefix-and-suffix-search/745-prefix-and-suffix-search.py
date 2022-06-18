class WordFilter:

    def __init__(self, words: List[str]):
        self.prefixes=defaultdict(set)
        self.suffixes=defaultdict(set)
        self.weights={}
        for index,word in enumerate(words):
            prefix=""
            suffix=""
            for char in [""]+list(word):
                prefix+=char
                self.prefixes[prefix].add(word)
            for char in [""]+list(word[::-1]):
                suffix+=char
                self.suffixes[suffix[::-1]].add(word)
            self.weights[word]=index     
                
        

    def f(self, prefix: str, suffix: str) -> int:
        weight=-1
        for word in self.prefixes[prefix] & self.suffixes[suffix]:
            weight=max(weight,self.weights[word])
        return weight    
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)