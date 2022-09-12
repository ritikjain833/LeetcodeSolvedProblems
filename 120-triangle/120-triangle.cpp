class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                //cout<<i<<" "<<j<<endl;
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==triangle[i].size()-1){
                    triangle[i][j]+=triangle[i-1][j-1];
                }
                
                else{
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                }
            }
        }
        int ans=INT_MAX;
        //cout<<"I am here";
        int n=triangle.size();
        for(int j=0;j<triangle[n-1].size();j++){
            ans=min(ans,triangle[n-1][j]);
        }
        return ans;
        
    }
};