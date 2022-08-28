class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        //i-j elements will be in same diagonal
        //store them in unordered_map
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        //sort each diagonal by ascending order
        //first index for will be -(n-1)=(0-(n-1))
        //last index will be m-1
        for(int k=-(n-1);k<m;k++){
            sort(mp[k].begin(),mp[k].end());
        }
        //traverse from back and update the matrices value by popping.
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
        
    }
};