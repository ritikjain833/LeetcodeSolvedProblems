class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        temp={}
        for i in range(65,91,1):
            temp[chr(i)]=i-64
        count=0    
        #use similar concept of binary to decimal here.
        for i in range(len(columnTitle)):
            count=count*26+temp[columnTitle[i]]
        return count   
            
