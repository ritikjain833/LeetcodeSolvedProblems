class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        '''Idea is to sort the products array and use the concept of two pointer approach'''
        
        products.sort()
        res=[]
        left=0
        right=len(products)-1
        for i in range(len(searchWord)):
            char=searchWord[i]
            #first check the condition and then check if sufficients characters are there in it or not product[left]/product[right] or if there is character mismatch then increase/decrease the corresponding pointer respectively.
            while left<=right and (len(products[left])<=i or products[left][i]!=char):
                left+=1
            while left<=right and (len(products[right])<=i or products[right][i]!=char):
                right-=1
            aux=[]    
            for j in range(left,min(right+1,left+3)):
                aux.append(products[j])
            res.append(aux)    
                
                    
        return res
        