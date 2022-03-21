class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        temp={}
        #store first and last occurence in a dictionary or hash table
        for i in range(len(s)):
            if s[i] not in temp:
                temp[s[i]]=[i,i]
            else:
                aux1,aux2=temp[s[i]]
                temp[s[i]]=[aux1,i]
        #sort the dictionary by first value or first occurence        
        temp=dict(sorted(temp.items(), key=lambda item: item[1][0]))
        #print(temp)
        ans=[]
        aux1,aux2=501,501
        #iterate over dictionary
        for key,val in temp.items():
            val1=val[0]
            val2=val[1]
            #base case as aux1>val1 occurs only for first key,val pair other than it is sorted so always go in else part
            if val1<aux1 and val2<aux2:
                aux1=val1
                aux2=val2
            #found a unique partition so append and change the boundary values.    
            elif aux2<val2 and val1>aux2:
                ans.append(aux2-aux1+1)
                aux1=val1
                aux2=val2
            #update boundary value    
            elif aux2<val2:
                aux2=val2
            #print(ans)  
        #last value append    
        ans.append(aux2-aux1+1)    
        return ans            
                
            
        
