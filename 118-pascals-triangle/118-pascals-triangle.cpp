class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=1;i<=n;i++){
            vector<int> temp(i,0);
            res.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<res[i].size();j++){
                if(j==0 or (j==res[i].size()-1)){
                    res[i][j]=1;
                }
                else if (i>=1 and j>=1){
                    res[i][j]=res[i-1][j-1]+res[i-1][j];
                }
            }
        }
        return res;
        
        
    }
};