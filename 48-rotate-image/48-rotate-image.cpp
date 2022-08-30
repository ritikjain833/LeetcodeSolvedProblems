class Solution {
public:
    int n;
    void transpose(vector<vector<int>> &matrix){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rev(vector<vector<int>> &matrix){
        for(int i=0;i<n;i++){
            int j=0;
            int k=n-1;
            while (j<k){
                swap(matrix[i][k],matrix[i][j]);
                j++;
                k--;
            }
        }
        
    }
    void rotate(vector<vector<int>>& matrix) {
        //for rotating the image two operations are required
        //first is transpose and then rev values of col
        n=matrix.size();
        transpose(matrix);
        
        rev(matrix);
        
    }
};