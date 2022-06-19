class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        res=[]
        left=0
        right=len(products)-1
        for i in range(len(searchWord)):
            char=searchWord[i]
            while left<=right and (len(products[left])<=i or products[left][i]!=char):
                left+=1
            while left<=right and (len(products[right])<=i or products[right][i]!=char):
                right-=1
            aux=[]    
            for j in range(left,min(right+1,left+3)):
                aux.append(products[j])
            res.append(aux)    
                
                    
        return res
        