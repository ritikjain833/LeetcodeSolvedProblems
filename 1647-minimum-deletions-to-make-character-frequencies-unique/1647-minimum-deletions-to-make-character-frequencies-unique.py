class Solution:
    def minDeletions(self, s: str) -> int:
        aux=Counter(s)
        ans=[]
        for i,j in aux.items():
            ans.append(j)
        ans.sort()    
        count=0
        mini=ans[0]
        mp=set()
        mp.add(mini)
        #print(ans)
        for i in range(1,len(ans)):
            if ans[i]!=ans[i-1]:
                mp.add(ans[i])
                continue
            else:
                aux=ans[i]
                #print(aux,mp)
                for i in range(aux,-1,-1):
                    if i==0:
                        count+=(aux-i)
                        mp.add(i)
                    elif i not in mp:
                        mp.add(i)
                        count+=(aux-i)
                        break
                        
        return count        
                
        
            
        