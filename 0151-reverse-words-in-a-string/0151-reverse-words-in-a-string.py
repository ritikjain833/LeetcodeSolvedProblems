class Solution:
    def reverseWords(self, s: str) -> str:
        aux=s.split(" ")
        temp=aux[::-1]
        f=[]
        for x in temp:
            if x!="":
                f.append(x)
        return " ".join(f)