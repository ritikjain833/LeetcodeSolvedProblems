class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> matrix(n, vector<int>(n));
        int r1=0,r2=n,c1=0,c2=n;
        int count=1;
        while (count<=n*n){
            for(int i=c1;i<c2;i++){
                matrix[r1][i]=count;
                count++;
            }
            r1++;
            for(int i=r1;i<r2;i++){
                matrix[i][c2-1]=count;
                count++;
            }
            c2--;
            if (r1<r2){
                for(int i=c2-1;i>c1-1;i--){
                matrix[r2-1][i]=count;
                count++;
            }
             
            
            }
            r2--;
            if (c1<c2){
                for(int i=r2-1;i>r1-1;i--){
                matrix[i][c1]=count;
                count++;
            }
            
                
            
            }
            c1++;
            
        }
        return matrix;
    }
};