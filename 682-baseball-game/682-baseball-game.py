from collections import deque
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        score=0
        val=deque()
        for aux in ops:
            if aux=="+":
                temp=(int(val[-1])+int(val[-2]))
                score+=temp
                val.append(temp)
            elif aux=="C":
                temp=val.pop()
                score-=temp
            
            elif aux=="D":
                val.append(int(val[-1])*2)
                score+=int(val[-1])
            else:
                val.append(int(aux))
                score+=int(val[-1])
            #print(score)
            #print(val)
            
            
        return score