class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        count_alice=0
        n=len(colors)
        count_bob=0
        for i in range(1,n-1):
            if colors[i]==colors[i+1]==colors[i-1]=="A":
                count_alice+=1
            elif colors[i]==colors[i+1]==colors[i-1]=="B":
                count_bob+=1
        if count_alice>count_bob:
            return True
        else:
            return False
        