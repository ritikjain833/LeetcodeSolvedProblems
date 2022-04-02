class Solution:
    def dfs(self,image,r,c,color,newColor,directions):
        if r>=0 and c>=0 and r<len(image) and c<len(image[0]) and image[r][c]==color:
            
            image[r][c]=newColor
            for dr,dc in directions:
                nr=r+dr
                nc=c+dc
                self.dfs(image,nr,nc,color,newColor,directions)
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
                
        color=image[sr][sc]
        directions=[[-1,0],[1,0],[0,1],[0,-1]]
        if (color!=newColor):
            self.dfs(image,sr,sc,color,newColor,directions)
        return image    
        
        