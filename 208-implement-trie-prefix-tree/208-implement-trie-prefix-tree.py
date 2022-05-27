class Trie:

    def __init__(self):
        self.root={}
        

    def insert(self, word: str) -> None:
        current_node=self.root
        for char in word:
            if not current_node.get(char):
                current_node[char]={}
            current_node=current_node[char]
        current_node["#"]=True    
        

    def search(self, word: str) -> bool:
        current_node=self.root
        for char in word:
            if not current_node.get(char):
                return False
            current_node=current_node[char]
        return current_node.get("#")
    

    def startsWith(self, prefix: str) -> bool:
        current_node=self.root
        for char in prefix:
            if not current_node.get(char):
                return False
            current_node=current_node[char]
        return True    
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)